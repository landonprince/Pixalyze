# Pixalyze 
> Real-time image analysis & processing application

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)

## Description
Pixalyze is an easy-to-use _command-line application_. It allows for the use of an evergrowing collection of commands to analyze and process images.
This application primarily utilizes the OpenCV library to rapidly parse and manipulate images in real-time. 

## Tools
- __OS:__ Windows 11 64-bit
- __IDE:__ CLion 2024.1.1
- __Compiler:__ Visual Studios 2022 17.0
- __Build Tool:__ CMake 2.28.1
- __Library Manager:__ Chocolatey 2.2.2
- __Libraries:__ OpenCV 4.9.0

## Installation
- ### Install Chocolatey library manager
  - Run Powershell as administrator and run the following command:
  - ```
    Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
- ### Install OpenCV library
  - Run Powershell as administrator and run the following command:
  - ```
    choco install opencv   
- ### Set up system & environment variables
  - Open 'Environment Variables,' and add the following system variables:
  - ```
    OPENCV_DIR           | C:\tools\opencv\build\x64\vc14\lib
    OPENCV_INCLUDE_PATHS | C:\tools\opencv\build\include
    OPENCV_LINK_LIBS     | opencv_world460
    OPENCV_LINK_PATHS    | C:\tools\opencv\build\x64\vc15\lib
    OPENCV_PATH          | C:\tools\opencv
  - Double-click on 'PATH' and add the following environment variable: 
  - ```
    User Variables / Path / C:\tools\opencv\build\x64\vc15\bin
