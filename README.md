ESPhome
======

ESP8266 specific library for use with ESP8266 according to the project described in board.jpeg

* Author: Rodrigo Lange (https://www.easysmart.com.br)
* Copyright (C) 2015-2022 Rodrigo Lange.
* Released under the MIT license.

Description
-----------
This library allows you to use callback functions to track changes in the states of garage door limit sensors, barrier sensors, and occupancy sensors. It also detects the status of the courtesy light relay of generic boards.
It has basic alarm and garden light control functions (reflector type, courtesy light, traffic light, etc).
Works with specific pins.
Consult the project to better understand its use.

Has been tested with ESP8266 devices (ESP12F, NodeMCU v1.0 and ESP12e only)

How To Use
----------
This library allows you to use the ESP8266 as a basic alarm kit, remote garage door starter and control a relay output which can be a garden light, traffic light or reflector.
It can be integrated with Blynk, ESPAlexa, Sinric Pro, NODERed, MQTT, HTTPServer, etc...

Notes
-----

- To see the latest changes to the library please take a look at the [Changelog](https://github.com/rodrigo-s-lange/ESPhome/CHANGELOG.md).
 
- And if you find this library helpful, please consider giving it a star at [GitHub](https://github.com/rodrigo-s-lange/ESPhome). Thanks!

Installation
------------
Download the ZIP archive (https://update.easysmart.com.br/ESPhome.zip), and choose "Sketch > Include Library > Add .ZIP Library..." and select the downloaded file.

License
-------

MIT License

Copyright (c) 2015-2022 Rodrigo Lange https://easysmart.com.br

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
