import "./style.css";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls";
import { RGBELoader } from "three/examples/jsm/loaders/RGBELoader.js";
import { EquirectangularReflectionMapping } from "three";

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// CUBE

// const geometry = new THREE.BoxGeometry(1, 1, 1);
// const material = new THREE.MeshPhongMaterial({ color: 0x00ffff });
// const cube = new THREE.Mesh(geometry, material);
// scene.add(cube);

// const ambientLight = new THREE.AmbientLight(0x404040);
// const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
// ambientLight.add(directionalLight);
// scene.add(ambientLight);

// function animate() {
//   cube.rotation.x += 0.01;
//   cube.rotation.y += 0.01;
//   cube.rotation.z += 0.01;
//   requestAnimationFrame(animate);
//   renderer.render(scene, camera);
// }
// animate();

// camera.position.z = 5;

const hdrURL = new URL("../img/kitchen.hdr", import.meta.url);
const orbit = new OrbitControls(camera, renderer.domElement);
camera.position.set(0, 0, 7);
orbit.update();

renderer.outputEncoding = THREE.sRGBEncoding;
renderer.toneMapping = THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure = 0.7;

const loader = new RGBELoader();
loader.load(hdrURL, function (texture) {
  texture.mapping = EquirectangularReflectionMapping;
  scene.background = texture;
  scene.environment = texture;
  const sphere = new THREE.Mesh(
    new THREE.SphereGeometry(1, 50, 50),
    new THREE.MeshStandardMaterial({roughness: 0,metalness: 0.9})
  );
  scene.add(sphere);
});

function animate() {
  renderer.render(scene, camera);
}

renderer.setAnimationLoop(animate);
