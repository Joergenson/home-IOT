<div id="top"></div>

![GitHub contributors](https://img.shields.io/github/contributors/joergenson/home-IOT)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/joergenson/home-iot)
![GitHub forks](https://img.shields.io/github/forks/joergenson/home-IOT?style=social)
![GitHub Repo stars](https://img.shields.io/github/stars/joergenson/home-iot?style=social)
[![MIT License][license-shield]][license-url]


<h1 align="center">Web server project</h1>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#setting-up-a-applet">Setting up a applet</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About the project

This project connects a smart home device with an ESP8266 using IFTTT.

The project consists of a data directory containing HTML and CSS files, and a 
sketch for the ESP8266.

It is an experiment to see if I could turn on my server using a smart 
plug instead of sending a signal to in while in sleep mode. This should save 
some power. However it has many other possibilities as it can be used to apply 
IoT features to items without them.

### Built With

* [C++]()
* [HTML]()
* [CSS]()
* [Arduino IDE](https://www.arduino.cc/en/Guide)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

<p align="right">(<a href="#top">back to top</a>)</p>


### Prerequisites

* An ESP8266
* A Smart plug(Or any IoT device) that allows the use of IFTTT 
* An IFTTT profile
* Setup a applet

<p align="right">(<a href="#top">back to top</a>)</p>


### Setting up a applet

1. Create an account on [IFTTT](https://ifttt.com/)
2. Create an applet
![Create](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/create.png?raw=true)
3. Choose webhook service
![Service](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/service.png?raw=true)
4. Set a trigger field
![Trigger](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/set_trigger_field.png?raw=true)
5. Then select the service you want the webhook to interact with.
![ThenThat](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/thenthat.png?raw=true)
6. Try the webhook out by going to documentation. Use the link when setting up the project
![WebDoc](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/webhookdoc.png?raw=true)
<p align="right">(<a href="#top">back to top</a>)</p>


### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Joergenson/home-IOT.git
   ```
2. Enter your credentials in `Web-Server.ino`
   ```c++
   const char* ssid = "YOUR SSID";
   const char* password = "YOUR PASSWORD";
   ```
3. Enter your host info in `Web-Server.ino`
   ```c++
   const char* hostname = "SERVER_IP";
   const char* IFTTTHostname = "APPLET WEBHOOK ADDRESS";
   ````
4. Upload the sketch  
<p align="right">(<a href="#top">back to top</a>)</p>

## Usage

Go to 
```
http://{ESPIP}/index
```
It should respond with a html like this
![Server](https://github.com/Joergenson/home-IOT/blob/main/ESP-webserver/images/server.png?raw=true)

In my case the application can turn on the server but not off. So when using the
 toggle it locks itself and you have to turn the server off via ssh acces.

<p align="right">(<a href="#top">back to top</a>)</p>


## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Simon jørgensen - sijo819@student.sdu.dk

Project Link: [https://github.com/Joergenson/home-IOT](https://github.com/Joergenson/home-IOT)

<p align="right">(<a href="#top">back to top</a>)</p>


[license-shield]: https://img.shields.io/github/license/joergenson/home-iot
[license-url]: https://github.com/Joergenson/home-IOT/blob/main/LICENSE