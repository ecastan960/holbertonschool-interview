#!/usr/bin/node
const request = require('request');
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, function (error, response, body) {
  characters = JSON.parse(body);
  characters = characters.characters;
  for (const character of characters) {
    request(`${character}`, function (error, response, body) {
      let name = JSON.parse(body);
      console.log(name.name);
    });
  }
});
