# ESP32-LED-Web-Control-Challenge1
# LED Control with ESP32 Web Server

This project demonstrates how to control LEDs connected to an ESP32 using a web interface. The project uses the ESP32's Wi-Fi capability to host a web server, allowing users to toggle the state of LEDs via a browser.

## Features
- Control red and green LEDs through a web interface.
- Simple HTML interface with toggle switches.
- Real-time state changes reflected on the webpage.

## Prerequisites
1. **Hardware**:
   - ESP32 microcontroller.
   - Red LED connected to GPIO 20.
   - Green LED connected to GPIO 39.
   - Appropriate resistors for the LEDs.
   
2. **Software**:
   - Arduino IDE with ESP32 board support.
   - Wi-Fi credentials.

## Project Structure
The code includes the following components:
- **WiFi setup**: Connects the ESP32 to a Wi-Fi network.
- **Web server setup**: Hosts an HTML interface to control LEDs.
- **HTML and JavaScript**: Provides the user interface and functionality to toggle LEDs.
- **Handlers for HTTP requests**: Toggle LED states on receiving specific commands.

## Setup Instructions
1. **Install ESP32 Board Support**:
   - In Arduino IDE, go to *File > Preferences*.
   - Add `https://dl.espressif.com/dl/package_esp32_index.json` to the *Additional Board Manager URLs*.
   - Go to *Tools > Board > Boards Manager*, search for `esp32`, and install.

2. **Connect Your ESP32**:
   - Use a USB cable to connect the ESP32 to your computer.

3. **Configure Wi-Fi Credentials**:
   Replace the following in the code:
   ```cpp
   const char* ssid = "Your_SSID";
   const char* password = "Your_PASSWORD";
   ```

4. **Upload the Code**:
   - Select the appropriate board and port from *Tools*.
   - Click *Upload*.

5. **Access the Web Interface**:
   - After uploading, open the Serial Monitor to get the ESP32's IP address.
   - Enter the IP address in a web browser to access the LED control interface.

## Web Interface
The interface allows users to toggle the red and green LEDs:
- **Red LED**: Toggle using the red switch.
- **Green LED**: Toggle using the green switch.

## Circuit Diagram
Connect the components as follows:
- **Red LED**: GPIO 20 through a resistor.
- **Green LED**: GPIO 39 through a resistor.
- Both LEDs share a common ground.

## Notes
- Ensure the GPIO pins used in the code match your hardware setup.
- If the ESP32 fails to connect to Wi-Fi, double-check the SSID and password.

## License
This project is open-source and free to use under the MIT License.
