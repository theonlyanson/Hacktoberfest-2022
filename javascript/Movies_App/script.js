const APIURL ="https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=04c35731a5ee918f014970082a0088b1&page=1";
const IMGPATH = "https://image.tmdb.org/t/p/w1280";
const SEARCHAPI ="https://api.themoviedb.org/3/search/movie?&api_key=04c35731a5ee918f014970082a0088b1&query=";

const main = document.getElementById('main');
const form = document.getElementById('form');
const search = document.getElementById('search');

getMovie(APIURL);//initially get movie

async function getMovie(url) {
    const resp = await fetch(url);
    const respData = await resp.json();

  /* respData.results.forEach(movie => {
       const img = document.createElement('img');
       img.src = IMGPATH + movie.poster_path;
      document.body.appendChild(img);
   });*/
   console.log(respData);
   showMovies(respData.results);
}    

function showMovies(movies) {
  // clear main
  main.innerHTML = "";

  movies.forEach((movie) => {
      const { poster_path, title, vote_average, overview } = movie;

      const movieEl = document.createElement("div");
      movieEl.classList.add("movie");

      movieEl.innerHTML = `
          <img
              src="${IMGPATH + poster_path}"
              alt="${title}"
          />
          <div class="movie-info">
              <h3>${title}</h3>
              <span>${vote_average}</span>
          </div>
          <div class="overview">
              <h3>Overview:</h3>
              ${overview}
          </div>
      `;

      main.appendChild(movieEl);
  });
}

form.addEventListener("submit", (e) => {
  e.preventDefault();

  const searchTerm = search.value;

  if (searchTerm) {
      getMovie(SEARCHAPI + searchTerm);

      search.value = "";
  }
});