import "./styles.css";
import React, { useState, useEffect } from "react";
import axios from "axios";

export default function App() {
  const [pokemon, setPokemon] = useState({
    name: "",
    type: "",
    img: ""
  });

  const fetchPokemon = (pokemon) => {
    axios
      .get(
        `https://pokeapi.co/api/v2/pokemon/${Math.floor(Math.random() * 100)}`
      )
      .then((res) => {
        console.log(res.data);
        setPokemon({
          name: res.data.name,
          type: res.data.types[0].type.name,
          img: res.data.sprites.front_default
        });
      })
      .catch((err) => {
        console.error(err);
      });
  };

  useEffect(() => {
    fetchPokemon();
  }, []);

  return (
    <div className="App">
      <h1>POKEDEX</h1>
      <h2>See some Random Pokemons</h2>
      <h3>{pokemon.name}</h3>
      <h3>{pokemon.type}</h3>
      <img src={pokemon.img} />
    </div>
  );
}
