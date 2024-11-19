#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "";
const char* password = "";

// Set GPIO pins for the LEDs
const int redLedPin = 20; 
const int greenLedPin = 39;
bool redLedState = false;
bool greenLedState = false;

// Create a web server object
WebServer server(80);

// Function to handle the root path
void handleRoot() {
  String html = "<!DOCTYPE html>";
  html += "<html><head><title>LED Control</title>";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; text-align: center; margin: 20px; }";
  html += ".toggle-container { display: flex; justify-content: center; align-items: center; gap: 20px; }";
  html += ".switch { position: relative; display: inline-block; width: 60px; height: 34px; }";
  html += ".switch input { display: none; }";
  html += ".slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: red; transition: 0.4s; border-radius: 34px; }";
  html += ".slider:before { position: absolute; content: ''; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; transition: 0.4s; border-radius: 50%; }";
  html += "input:checked + .slider { background-color: green; }";
  html += "input:checked + .slider:before { transform: translateX(26px); }";
  html += "</style>";
  html += "</head><body>";
  html += "<h1>ESP32 LED Control</h1>";
  html += "<div class='toggle-container'>";
  html += "<div>";
  html += "<p>Red LED</p>";
  html += "<label class='switch'>";
  html += "<input type='checkbox' id='redLed' onchange='toggleRed()' ";
  if (redLedState) html += "checked";
  html += "><span class='slider'></span></label>";
  html += "</div>";
  html += "<div>";
  html += "<p>Green LED</p>";
  html += "<label class='switch'>";
  html += "<input type='checkbox' id='greenLed' onchange='toggleGreen()' ";
  if (greenLedState) html += "checked";
  html += "><span class='slider'></span></label>";
  html += "</div>";
  html += "</div>";
  html += "<script>";
  html += "function toggleRed() { fetch('/toggleRed'); }";
  html += "function toggleGreen() { fetch('/toggleGreen'); }";
  html += "</script>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Function to toggle the red LED
void handleToggleRed() {
  redLedState = !redLedState;
  digitalWrite(redLedPin, redLedState ? HIGH : LOW);
  server.send(200, "text/plain", "Red LED Toggled");
}

// Function to toggle the green LED
void handleToggleGreen() {
  greenLedState = !greenLedState;
  digitalWrite(greenLedPin, greenLedState ? HIGH : LOW);
  server.send(200, "text/plain", "Green LED Toggled");
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Configure LED pins as outputs
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Configure web server routes
  server.on("/", handleRoot);
  server.on("/toggleRed", handleToggleRed);
  server.on("/toggleGreen", handleToggleGreen);

  // Start the server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  // Handle incoming HTTP requests
  server.handleClient();
}