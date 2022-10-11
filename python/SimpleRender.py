import pyglet
from pyglet import image
import numpy as np
import numba

WINDOW_W = 800
WINDOW_H = 600


def vector(x):
    return np.array(x, dtype='float32')


class Vertex:
    def __init__(self, pos=None, tex_coor=None, norm=None, rhw=None):
        self.pos = pos if pos is not None else np.zeros(4)
        self.tex_coor = tex_coor if tex_coor is not None else np.zeros(2)
        self.norm = norm if norm is not None else np.zeros(3)
        self.rhw = rhw if rhw else 0

    def copy(self):
        return Vertex(pos=self.pos.copy(),
                      tex_coor=self.tex_coor.copy(),
                      norm=self.norm.copy(),
                      rhw=self.rhw)


class Device:
    RENDER_STATE_WIREFRAME = 1
    RENDER_STATE_TEXTURE = 2

    def __init__(self, width, height):
        self.lights = dict(dir=[])
        self._texture = None

        self.state = Device.RENDER_STATE_TEXTURE
        self._frame_buffer = np.zeros((height, width, 4), dtype='uint8')
        self._z_buffer = np.zeros((height, width), dtype='float')

        self.width = width
        self.height = height

        self._world_trans = np.eye(4)
        self._view_trans = np.eye(4)
        self._projection_trans = np.eye(4)
        self._trans = np.eye(4)
        self._norm_trans = np.zeros(3)
        self.set_perspective(np.pi * 0.5, float(self.width) / self.height, 1.0, 500)

    def set_texture(self, texture):
        self._texture = texture

    @staticmethod
    def make_transform(scale=None, rotate=None, translate=None):
        """
        scale: (scalex, scaley, scalez)
        rotate: (x, y, z, theta). <x, y, z> indicate the axis rotated by,
                theta is the degree of rotation
        translate: (translatex, translatey, translatez)
        """
        res = np.eye(4)

        if scale:
            tmp_matrix = np.eye(4)
            tmp_matrix[0, 0] = scale[0]
            tmp_matrix[1, 1] = scale[1]
            tmp_matrix[2, 2] = scale[2]
            res = np.dot(res, tmp_matrix)

        if rotate:
            tmp_matrix = np.eye(4)
            x, y, z = Device._normalize(vector(rotate[:3]))
            theta = rotate[3]

            cos = np.cos(theta)
            one_sub_cos = 1 - cos
            sin = np.sin(theta)
            tmp_matrix[0, 0] = cos + one_sub_cos * x ** 2
            tmp_matrix[0, 1] = one_sub_cos * x * y - sin * z
            tmp_matrix[0, 2] = one_sub_cos * x * z + sin * y
            tmp_matrix[1, 0] = one_sub_cos * y * x + sin * z
            tmp_matrix[1, 1] = cos + one_sub_cos * y ** 2
            tmp_matrix[1, 2] = one_sub_cos * y * z - sin * x
            tmp_matrix[2, 0] = one_sub_cos * z * x - sin * y
            tmp_matrix[2, 1] = one_sub_cos * z * y + sin * x
            tmp_matrix[2, 2] = cos + one_sub_cos * z ** 2
            res = np.dot(res, tmp_matrix)

        if translate:
            tmp_matrix = np.eye(4)
            tmp_matrix[0, 3] = translate[0]
            tmp_matrix[1, 3] = translate[1]
            tmp_matrix[2, 3] = translate[2]
            res = np.dot(res, tmp_matrix)

        return res

    @staticmethod
    def _normalize(vec):
        n = np.linalg.norm(vec)
        return vec / n if n != 0 else vec

    def set_camera(self, eye, at, up):

        z = Device._normalize((at - eye)[:3])
        x = Device._normalize(np.cross(up[:3], z))
        y = Device._normalize(np.cross(z, x))

        tmp_matrix = np.eye(4)
        tmp_matrix[0, :3] = x
        tmp_matrix[1, :3] = y
        tmp_matrix[2, :3] = z
        tmp_matrix[3, 0] = -np.dot(x, eye[:3])
        tmp_matrix[3, 1] = -np.dot(y, eye[:3])
        tmp_matrix[3, 2] = -np.dot(z, eye[:3])

        self._view_trans = tmp_matrix
        self.update_transform()

    def set_perspective(self, fov, aspect, zn, zf):
        tmp_matrix = np.zeros((4, 4))
        cot = 1. / np.tan(fov / 2.)
        tmp_matrix[0, 0] = cot / aspect
        tmp_matrix[1, 1] = cot
        tmp_matrix[2, 2] = zf / (zf - zn)
        tmp_matrix[2, 3] = 1
        tmp_matrix[3, 2] = zf * zn / (zn - zf)

        self._projection_trans = tmp_matrix
        self.update_transform()

    def set_world_trans(self, transform):
        self._world_trans = transform
        self.update_transform()

    def update_transform(self):
        tmp_trans = np.dot(self._world_trans, self._view_trans)
        self._trans = np.dot(tmp_trans, self._projection_trans)
        self._norm_trans = np.linalg.inv(self._world_trans[:3, :3]).T

    def transform(self, v):
        # transform
        transformed_v = np.dot(v, self._trans)
        w = transformed_v[3]

        # homogenize
        transformed_v /= transformed_v[3]
        transformed_v[0] = (transformed_v[0] + 1) * self.width * 0.5
        transformed_v[1] = (1 - transformed_v[1]) * self.height * 0.5
        transformed_v[3] = w

        return transformed_v

    def transform_norm(self, v):
        return np.dot(v, self._norm_trans)

    def clear_frame_buffer(self, color=vector([0, 0, 0, 255])):
        self._frame_buffer[..., 0] = color[0]
        self._frame_buffer[..., 1] = color[1]
        self._frame_buffer[..., 2] = color[2]
        self._frame_buffer[..., 3] = color[3]

    def clear_z_buffer(self):
        self._z_buffer[...] = 0

    def get_frame_buffer_str(self):
        return self._frame_buffer.tostring()

    def draw_line(self, x0, y0, x1, y1, color=vector([255, 255, 255, 255])):
        """
        Bresenham line drawing
        x0, y0, x1, y1 must be integer
        """
        steep = np.abs(y1 - y0) > np.abs(x1 - x0)
        if steep:
            x0, y0 = y0, x0
            x1, y1 = y1, x1
        if x0 > x1:
            x0, x1 = x1, x0
            y0, y1 = y1, y0
        delta_x = x1 - x0
        delta_y = np.abs(y1 - y0)
        error = delta_x / 2

        y = y0
        if y0 < y1:
            y_step = 1
        else:
            y_step = -1

        for x in xrange(x0, x1):
            if steep:
                self._frame_buffer[y, x, :] = color
            else:
                self._frame_buffer[x, y, :] = color
            error = error - delta_y
            if error < 0:
                y += y_step
                error += delta_x

    @staticmethod
    def _interp(x1, x2, t):
        return (x2 - x1) * t + x1

    @staticmethod
    def _vertex_init_rhw(v):
        rhw = 1.0 / v.pos[3]
        v.rhw = rhw
        v.tex_coor *= rhw

    @staticmethod
    def _vertex_interp(x1, x2, t):
        res = Vertex()
        res.pos = Device._interp(x1.pos, x2.pos, t)
        res.pos[3] = 1
        res.tex_coor = Device._interp(x1.tex_coor, x2.tex_coor, t)
        res.norm = Device._interp(x1.norm, x2.norm, t)
        res.rhw = Device._interp(x1.rhw, x2.rhw, t)
        return res

    @staticmethod
    def _trapezoid_triangle(v1, v2, v3):
        """
        v1, v2, v3: Vertex obj.
        ret list of trapezoid 0~2
        """
        # sort by pos[1]
        if v1.pos[1] < v2.pos[1]:
            v1, v2 = v2, v1
        if v1.pos[1] < v3.pos[1]:
            v1, v3 = v3, v1
        if v2.pos[1] < v3.pos[1]:
            v2, v3 = v3, v2

        # collinear
        if v1.pos[1] == v2.pos[1] and v2.pos[1] == v3.pos[1]:
            return []
        if v1.pos[0] == v2.pos[0] and v2.pos[0] == v3.pos[0]:
            return []

        # triangle down
        if v1.pos[1] - v2.pos[1] < 0.5:
            if v1.pos[0] > v2.pos[0]:
                v1, v2 = v2, v1
            return ((v1, v3), (v2, v3)),
        # triangle up
        if v2.pos[1] - v3.pos[1] < 0.5:
            if v2.pos[0] > v3.pos[0]:
                v2, v3 = v3, v2
            return ((v1, v2), (v1, v3)),

        t = (v2.pos[1] - v3.pos[1]) / (v1.pos[1] - v3.pos[1])

        middle = Device._vertex_interp(v3, v1, t)

        if middle.pos[0] < v2.pos[0]:  # middle on the left
            return (((v1, middle), (v1, v2)),  # top tri - left edge, right edge
                    ((middle, v3), (v2, v3)))  # bottom tri - left edge, right edge
        else:
            return (((v1, v2), (v1, middle)),  # top tri - left edge, right edge
                    ((v2, v3), (middle, v3)))  # bottom tri - left edge, right edge

    @staticmethod
    def _texture_readline(tex, start, end, sample_nums, rhw):
        """
        Get a line of pixel on tex from start to end
        :param tex: the texture
        :param start: start vertex location
        :param end: end vertex location
        :param sample_nums: how many value will be sampled in this line
        :param rhw: rhw
        :return: the pixel value in an np.ndarray
        """
        h, w, c = tex.shape
        h -= 1
        w -= 1

        start_tex = start.tex_coor[0] * w, start.tex_coor[1] * h
        end_tex = end.tex_coor[0] * w, end.tex_coor[1] * h

        if sample_nums != 0:
            x = (np.linspace(start_tex[0], end_tex[0], sample_nums) / rhw + 0.5).astype(int)
            y = (np.linspace(start_tex[1], end_tex[1], sample_nums) / rhw + 0.5).astype(int)

            return tex[y, x]
        else:
            return tex[start_tex[1], start_tex[0]]

    def _draw_scan_line(self, trapezoid):
        """
        Draw scan line in trapezoid
        :param trapezoid: a trapezoid, a tuple which returned by _trapezoid_triangle
        :return: void
        """
        left_edge = trapezoid[0]
        right_edge = trapezoid[1]

        bottom = int(left_edge[1].pos[1] + 0.5)
        top = int(left_edge[0].pos[1] + 0.5)

        for cur_y in xrange(bottom, top):

            t = float(cur_y - bottom) / (top - bottom)

            start = Device._vertex_interp(left_edge[1], left_edge[0], t)
            end = Device._vertex_interp(right_edge[1], right_edge[0], t)

            if cur_y < 0: continue
            if cur_y >= self.height: break

            y = int(start.pos[0] + 0.5)
            r = int(end.pos[0] + 0.5)
            sample_nums = r - y + 1

            # clip
            if y < 0 < r:
                y = 0
            elif y <= r < 0:
                continue

            if r >= self.width > y:
                r = self.width - 1
            elif r >= y > self.width:
                continue

            z_buffer = self._z_buffer[cur_y, y:r + 1]
            frame_buffer = self._frame_buffer[cur_y, y:r + 1]
            rhw = np.linspace(start.rhw, end.rhw, sample_nums)
            norm = np.vstack((np.linspace(start.norm[0], end.norm[0], sample_nums),
                              np.linspace(start.norm[1], end.norm[1], sample_nums),
                              np.linspace(start.norm[2], end.norm[2], sample_nums))).T

            tex_line = Device._texture_readline(self._texture, start, end, sample_nums, rhw)

            # clip
            clip_mask = np.arange(y, r + 1)
            clip_mask = (clip_mask >= 0) & (clip_mask < self.width)
            rhw = rhw[clip_mask]
            norm = norm[clip_mask, :]
            tex_line = tex_line[clip_mask, :]

            for light in self.lights['dir']:
                light_dir = Device._normalize(light['dir'])
                diffuse = np.maximum(np.atleast_2d(np.dot(norm, -light_dir)).T, 0) * light['diffuse']
                ambient = light['ambient']
                tex_line[:, :3] = np.minimum((diffuse + ambient) * tex_line[:, :3], 255)

            mask = z_buffer <= rhw
            frame_buffer[mask] = tex_line[mask]
            z_buffer[mask] = rhw[mask]

    @staticmethod
    def _is_backface(v1, v2, v3):
        """
        Determine if a triangle is clockwise or not. The algorithm is compute the signed area of triangle
        """
        m = np.vstack((v1.pos, v2.pos, v3.pos, v1.pos))
        return np.linalg.det(m[:2, :2]) + np.linalg.det(m[1:3, :2]) + np.linalg.det(m[2:4, :2]) >= 0

    def add_dir_light(self, direction, ambient, diffuse):
        self.lights['dir'].append(dict(dir=direction, ambient=ambient, diffuse=diffuse))

    def draw_primitive(self, v1, v2, v3):

        p1 = v1.copy()
        p2 = v2.copy()
        p3 = v3.copy()

        p1.pos = device.transform(v1.pos)
        p2.pos = device.transform(v2.pos)
        p3.pos = device.transform(v3.pos)

        p1.norm = device.transform_norm(v1.norm)
        p2.norm = device.transform_norm(v2.norm)
        p3.norm = device.transform_norm(v3.norm)

        # backface culling
        if self._is_backface(p1, p2, p3):
            return

        if self.state == Device.RENDER_STATE_WIREFRAME:
            self.draw_line(p1.pos[1].astype(int), p1.pos[0].astype(int),
                           p2.pos[1].astype(int), p2.pos[0].astype(int))
            self.draw_line(p2.pos[1].astype(int), p2.pos[0].astype(int),
                           p3.pos[1].astype(int), p3.pos[0].astype(int))
            self.draw_line(p3.pos[1].astype(int), p3.pos[0].astype(int),
                           p1.pos[1].astype(int), p1.pos[0].astype(int))
        elif self.state == Device.RENDER_STATE_TEXTURE:
            self._vertex_init_rhw(p1)
            self._vertex_init_rhw(p2)
            self._vertex_init_rhw(p3)

            trapezoids = self._trapezoid_triangle(p1, p2, p3)
            for trap in trapezoids:
                self._draw_scan_line(trap)
        else:
            raise Exception("Invalid Render state %s" % self.state)

    def draw_quad(self, v1, v2, v3, v4):
        self.draw_primitive(v1, v2, v3)
        self.draw_primitive(v3, v4, v1)

    def draw_mesh(self, vertices, indices):
        for i in indices:
            if len(i) == 3:
                self.draw_primitive(vertices[i[0]], vertices[i[1]], vertices[i[2]])
            else:
                self.draw_quad(vertices[i[0]], vertices[i[1]], vertices[i[2]], vertices[i[3]])


if __name__ == '__main__':
    game_window = pyglet.window.Window(WINDOW_W, WINDOW_H)
    device = Device(WINDOW_W, WINDOW_H)

    # define the mesh of box

    mesh = [
        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([0.0, 0.0, -1.0]), tex_coor=vector([0.0, 0.0]), rhw=1),

        Vertex(pos=vector([-0.5, -0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, 0.5, 1]), norm=vector([0.0, 0.0, 1.0]), tex_coor=vector([0.0, 0.0]), rhw=1),

        Vertex(pos=vector([-0.5, 0.5, 0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, -0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, 0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, 0.5, 1]), norm=vector([-1.0, 0.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),

        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, -0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, -0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, -0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, 0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([1.0, 0.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),

        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, -0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, 0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, -0.5, 0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, 0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, -0.5, -0.5, 1]), norm=vector([0.0, -1.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),

        Vertex(pos=vector([-0.5, 0.5, -0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([0.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, -0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([1.0, 1.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([0.5, 0.5, 0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([1.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, 0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([0.0, 0.0]), rhw=1),
        Vertex(pos=vector([-0.5, 0.5, -0.5, 1]), norm=vector([0.0, 1.0, 0.0]), tex_coor=vector([0.0, 1.]), rhw=1)]

    indices = [
               [0, 1, 2],
               [3, 4, 5],
               [8, 7, 6],
               [11, 10, 9],
               [14, 13, 12],
               [17, 16, 15],
               [18, 19, 20],
               [21, 22, 23],
               [26, 25, 24],
               [29, 28, 27],
               [30, 31, 32],
               [33, 34, 35]
               ]

    device.set_camera(eye=vector([0, 0, -3, 1]),
                      at=vector([0.23, 0, 0, 1]),
                      up=vector([0, 1, 0, 1]))

    # the rotate degree
    rotate_degree = 1

    frame = image.create(device.width, device.height)
    fps_display = pyglet.clock.ClockDisplay()

    # produce texture, chess board
    texture = np.ones((256, 256, 4), dtype='uint8') * 255
    grid_size = 32
    for i in range(grid_size):
        for j in [j * 2 for j in range(grid_size / 2)]:
            texture[i * grid_size:i * grid_size + grid_size,
            (j + (i % 2)) * grid_size:(j + (i % 2)) * grid_size + grid_size, :] = vector([1, 128, 255, 255])

    device.set_texture(texture)
    device.add_dir_light(vector([0, 0, 3]),
                         vector([0.05, 0.05, 0.05]),
                         vector([0.7, 0.7, 0.7]))


    @game_window.event
    def on_draw():
        game_window.clear()
        device.clear_frame_buffer(vector([128, 33, 78, 255]))
        device.clear_z_buffer()

        global rotate_degree
        trans = device.make_transform(rotate=(1, 1, 1, rotate_degree / np.pi * 180))
        device.set_world_trans(trans)
        rotate_degree += 0.0005
        rotate_degree %= 180

        # draw box
        device.draw_mesh(mesh, indices)

        frame.set_data(
            'RGBA', device.width * 4, device.get_frame_buffer_str())
        frame.blit(0, 0)
        # fps_display.draw()


    pyglet.clock.schedule_interval(lambda dt: None, 1 / 60.0)

    pyglet.app.run()
