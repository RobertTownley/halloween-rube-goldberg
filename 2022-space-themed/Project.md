# Candy Distribution Rube Golberg 2022: Space Themed

## Context

During the 2020 pandemic, people were staying 6 feet away from each other. Wanting to trick-or-treat safely, we started a tradition of building devices that distribute candy to kids from 6 feet away. Every year, it gets more thematic, complicated, and impressive as a project that Robert really enjoys building.

## 2022 Plan

2022 is going to be space themed. The experience goes as follows:

- Kids hit a plastic "liftoff" button positioned ~12 feet away from our porch
- That makes lights appear below a 3D printed rocket on the ground, in front of a blow-up projection of a launch tower
- An audio countdown sequence initiates
- When the countdown hits blastoff, the lights at the base of the rocket go out
- The projector switches to a video of a rocket flying through space, and approaching a planet
- When the rocket reaches the planet, the video goes dark
- Just off the top right of the projection screen, a physical planet lights up
- Within the physical planet, there's a bin filled with candy
- An automated scooper within the bin grabs some candy and tosses it over the side
- Off the side of the planet, a slope has been made to look like the trail of a shooting star
- Candy falls into the slope, down towards the kids and into a bin at their feet (near the original button)

## Acquisition/Build List:

- [ ] Launch button
  - https://www.amazon.com/dp/B00XRC9URW?psc=1&ref=ppx_yo2ov_dt_b_product_details
- Rocket
  - These balloons come with other things
    - https://www.amazon.com/Astronaut-Balloons-Inflatable-Spaceship-Supplies/dp/B09WMQH7R7/ref=sr_1_10?crid=H00IKP0D522D&keywords=inflatable+alien+planet&qid=1662222247&sprefix=inflatible+alien+planet%2Caps%2C65&sr=8-10
- Planet
  - I'm thinking maybe just a beach ball that we paint to look like a moon or planet?
    - https://www.amazon.com/Intex-42-Jumbo-Ball-2-Pack/dp/B00DIHAGS8/ref=sr_1_3?crid=2RGYC7YA6NQ3L&keywords=extra+large+beach+ball&qid=1662223078&refinements=p_36%3A1253560011&rnid=386491011&s=toys-and-games&sprefix=extra+large+beach+ball%2Caps%2C66&sr=1-3
- Ramp
  - Mostly cardboard, gotta acquire boxes to make into the right shape
  - Starry night table cloth, 108 inches long for the ramp
    - https://www.amazon.com/Tablecloth-Decorations-Galaxy-Supplies-Birthday/dp/B09MRV5HW8/ref=sr_1_3_sspa?crid=2EIB8D8QARRFO&keywords=space+tablecloth&qid=1662222712&s=home-garden&sprefix=space+tablecloth%2Cgarden%2C68&sr=1-3-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzSU4xVllBUFY5MklIJmVuY3J5cHRlZElkPUEwMDUxNTc2QzZGOEZTS01QOEwmZW5jcnlwdGVkQWRJZD1BMDg3NDY3N0VWM1JDVVoxSUNNWCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=

## Cost

- $10 for the launch button
- $10 for balloons
- $7 for starry night table cloth
- $15 for the planet beach ball(s)

TOTAL: $42

## Questions

- How to recharge the 3.75v batteries
  - Can be done via the board: charge via micro USB while the battery is plugged in
- How to drive the motor. Do I need a "driver circuit"?
  - I saw warnings about plugging the board directly into the DC power source, which can damage the board
  - I think I need "transistors" but they have weird letters, what do they mean?
    - https://www.amazon.com/BOJACK-General-Purpose-Transistors-Assortment/dp/B07T61SY9Y/ref=sr_1_5?crid=3CK13B0Q40758&keywords=24v+transistor&qid=1664690651&qu=eyJxc2MiOiIxLjk4IiwicXNhIjoiMS4zNyIsInFzcCI6IjAuMDAifQ%3D%3D&s=industrial&sprefix=24v+transistor%2Cindustrial%2C48&sr=1-5

## TODO

- [ ] Screen
  - [ ] Video of rocket
  - [x] Affirm screen works well
    - It does, but not during daylight :/
  - [ ] Practice placement of projector and table
- [ ] Button
  - [x] Make container pretty
    - Spray painted a trash can. Looks great
  - [ ] Communicate with python server
- [ ] Ramp
  - [x] Go to the Home Depot
  - [x] Lots of duct tape
  - [ ] Assemble ramp
  - [ ] LEDs if there's time
- [ ] Laptop
  - [ ] Get video onto laptop
  - [ ] Make python server play video when it receives the button signal
  - [ ] Make python server communicate to the motor when it receives the button signal
- [ ] Candy distribution machine
  - [x] Affix skewers to motor
  - [ ] Affix motor to container
  - [ ] Affix cups to kebab skewers
