const getElement = (element) => {
    return document.querySelector(element);
}

const requestPokeInfo = (url, name) => {
    fetch(url + name)
        .then(response => response.json())
        .then(data => { pokemon = data; })
        .catch(err => console.log(err));
}

const createCard = () => {
    console.table(pokemon.types)
    return `
        <div class="pokemon-picture">
            <img src="${pokemon.sprites.front_default}" alt="Sprite of ${pokemon.name}">
        </div>
        <ul class="pokemon-info">
            <li class="name"><strong>Nome:</strong>${pokemon.name}</li>
            <li class="number"><strong>Nº</strong> ${pokemon.id}</li>
            <li class="type"><strong>Tipo:</strong> ${pokemon.types.map(item => item.type.name).toString()}</li>
            <li class="skill"><strong>Habilidades:</strong> ${pokemon.moves.map(item => `<span>${item.move.name}</span>`)}</li>
            <li class="weight"><strong>Peso:</strong> ${pokemon.weight  / 10}kg</li>
            <li class="height"><strong>Altura:</strong>${pokemon.height  / 10}m</li>
        </ul>`;
}

function startApp(pokeName) {
    requestPokeInfo(URI, pokeName);

    setTimeout(() => {
        if(pokemon.detail) {
            erroMessage.style.display = 'block';
            container.style.display = 'none';
        } else {
            erroMessage.style.display = 'none';
            container.style.display = 'flex';
            container.innerHTML = createCard();
        }
    }, 2000);
}

const URI = "https://pokeapi.co/api/v2/pokemon/";

const searchInput = getElement('.search-input');
const searchButton = getElement('.search-button');
const container = getElement('.pokemon');
const erroMessage = getElement('.error');

let pokeName,
pokemon,
card;

searchButton.addEventListener('click', event => {
    event.preventDefault();
    pokeName = searchInput.value.toLowerCase();
    startApp(pokeName);
    container.classList.add('fade');

    setTimeout(() => {
        container.classList.remove('fade');
    }, 3000);
});