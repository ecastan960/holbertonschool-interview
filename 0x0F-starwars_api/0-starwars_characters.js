#!/usr/bin/node
const request = require('request');
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, async function (error, response, body) {
  if (error) console.log(error);
  else {
    let characters = JSON.parse(body);
    characters = characters.characters;
    for (const character of characters) {
      const name = () => {
        return new Promise((resolve, reject) => {
          request(`${character}`, function (error, response, body) {
            if (error) console.log(error);
            else {
              resolve(JSON.parse(body).name);
            }
          });
        });
      };
      console.log(await name());
    }
  }
});
