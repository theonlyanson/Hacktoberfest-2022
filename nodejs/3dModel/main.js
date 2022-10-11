import "./style.css";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls";
import { GLTFLoader } from "three/examples/jsm/loaders/GLTFLoader.js";
import { EquirectangularReflectionMapping } from "three";
import { RGBELoader } from "three/examples/jsm/loaders/RGBELoader.js";
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

// Bckgorund

renderer.outputEncoding = THREE.sRGBEncoding;
renderer.toneMapping = THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure = 0.9;

const hdrURL = new URL("../img/forest.hdr", import.meta.url);
camera.position.set(0, 0, 7);

const rgbeLoader = new RGBELoader();
rgbeLoader.load(hdrURL, function (texture) {
  texture.mapping = EquirectangularReflectionMapping;
  scene.background = texture;
  scene.environment = texture;
});

//object

const loader = new GLTFLoader();

loader.load("scene.gltf", function (gltf) {
  scene.add(gltf.scene);
});
scene.background = new THREE.Color(0xffffff);
const light = new THREE.HemisphereLight(0xffffff, 0x000000, 2);
scene.add(light);
camera.position.set(0, 0, 300);

const orbit = new OrbitControls(camera, renderer.domElement);
orbit.update();

function animate() {
  requestAnimationFrame(animate);
  renderer.render(scene, camera);
}

animate();
