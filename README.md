# Drone Simulation

## Team 001-18:
<ul>
  <li> Matthew Johnson (joh18723)
  <li> Grant Johnston (joh19060)
  <li> Ethan Johnson (joh18919)
  <li> Bek Allenson (alle1423)
</ul>

<br>

## Project Description

This project simulates a drone package delivery system, in which deliveries can be scheduled using various pathing algorithms for a delivery drone to move from a package to its recipient.

These deliveries can be scheduled individually, or in batches of 100 for testing. In these testing batches, 25 deliveries are randomly scheduled and run with all 4 pathing algorithms. Additionally, drones have a set amount of battery life available to move around the map. When a drone runs out of battery, it uses reserved power to travel to a battery station to charge, and then resume whatever it was doing. One battery station is automatically added to the map in a set location, and users can choose to add between 1 and 4 additional stations using the Schedule page.

When a delivery is started, a Singleton begins keeping track of the amount of time passed in the simulation between when the delivery starts and when the package is delivered - including any time needed to charge the drone mid-delivery.

Our aim with this project is to provide accurate data to a company looking to invest in a drone delivery system on the University of Minnesota - Twin Cities campus, providing data for the estimated time per delivery with different configurations of the number of battery stations and pathing algorithms.

## How to run the simulation

First, make sure that you have Docker installed and running on your machine. Then, pull the Docker image from Docker Hub using this command:

```docker pull johnstongrant/team-001-18-hw4```

Next, you can now run the program with this command:

``` docker run --rm -it -p 8081:8081 johnstongrant/team-001-18-hw4 ```

If you would like to run the program and witness the data collection portion run the following commands:
```docker run -it -p 8081:8081 --entrypoint=bash johnstongrant/team-001-18-hw4```
``` make -j```
``` make run```

Once you have felt as though you've collected enough deliveries, click the "stop simulation" on the website

From there enter this command into your terminal:
```cat data.csv```

You can now access the simulation by going to http://localhost:8081 on your web browser.

## What does the simulation do specifically

The drone is assigned a specific order, and will navigate directly to the package. After picking up the package, the drone will calulate its path along exiting routes using the algorithm specified using the drop down menu on the scheduling page. Following this path, the drone will deliver the package it is carrying to the robot customer. There are other entities in the simulation, such as a helicopter and a human, these entities do not provide any function, however, they add flavor to the simulation.

## New Feature 1: Batteries

We added a battery feature to the drone objects, as well as battery stations at which the drone can refuel. This is a valuable addition to the drone delivery simulation because drones in the real world do not have infinite battery supply, and recharging of the drones is an important aspect of this business model to consider. With our implementation of battery packs, stakeholders can get a better idea of the infrastructure that would be needed to create a drone delivery network. We implemented the battery stations using a factory pattern because it closely mirrors the creation of other entities in the simulation already, such as the human, robot, or helicopter. For the battery pack, we implemented it using the decorator pattern, because this pattern is the best for adding functionality to an existing object class without changing that class. This feature is not interactable, the drone will automatically use a beeline strategy to navigate to the nearest battery station when it detects that its charge is critically low. 

![image](https://media.github.umn.edu/user/27744/files/7c5ffe95-48f3-4b11-8182-d83cb3fa519f)

## New Feature 2: Data Collection

We added a feature that collects data about the simulation after each delivery. Specifically, the name of the entity making the delivery, the strategy it used to make the delivery, and the the time it took to make the delivery. When paired with the automated tests we created, it collects a spreadsheet of data that can be used to observe correlations between number of battery stations in the simulation, strategies used, and time it takes to make deliveries. Using the singleton design pattern, we created a single instance of a csv file and functions to help gather data for the csv. All facets of the system have access to this singleton instance to be able to use its functions to write data to the csv accordingly.

![image](https://media.github.umn.edu/user/19738/files/9f499350-6901-4a7b-889e-a61d62139305)

## Bug List

Currently our simulation has two known bugs that although don't disrupt the overall behaviors of our extensions would still be beneficial to address if we had more sprints planned out.

## Bug 1: Package Delivering itself/ Teleporting to Drone

This bug occurs semi rarely, but over the course of many tests at some point the drone becomes desynced with the package visually, but internally the behavior remains consistent. What this means is that the internal workings of our delivery implementation seems sound, but the visual representation of entities becomes less reliable. After some of these desync'd deliveries the drone will sometimes catch back up and return to a normal visual state.

It is important to note that our data collection continues to report accurate timings and associations to what drone delivered what package.

The other minor bug that happens during deliveries is when the drone hits its reserve battery. When the drone dips below a certain threshold it activates a sort of fail-safe function to drop whatever it is currently tasked with and finds the nearest station. This switch causes the package to be left behind, however once the drone has completed its refuel the package respawns underneath the drone as it completes its delivery. 

Again in real world scenario we would want the drone to carry the package with it to the station, recharge, and then continue. This behavior is internally happening, but the viusal representation was something that we couldn't iron out.

## Bug 2: Parse Error

Often, when running the simulation, many parse errors occur and be written out into the terminal. As stated by a TA on Piazza (Found here: https://piazza.com/class/ll2gghwszyi43l/post/475), this error is caused by some miscommunication between the front end and back end. Most of the time, when this parse error occurs, it is on an update command which does not effect the simulation much, just causes it to just loose a frame now and again.

## Sprint Retrospective

What went well:
- Team communication
- Even split of work
- All assigned tasks completed

What could be improved:
- We did not follow the scrum methodology as close as we could have. Doing so could have helped with time managment and deadlines.
- Splitting up tasks into smaller tasks on backlog. Some of the tasks were much larger than others.

What will we commit to improve in the next Sprint:
- Delegate smaller tasks for easier work loads. 
- Do more standup meetings to keep eachother updated on what we are working on.

## Links

Docker Image: https://hub.docker.com/r/johnstongrant/team-001-18-hw4

Youtube Presentation: https://youtu.be/mLS6BSSH_2A
