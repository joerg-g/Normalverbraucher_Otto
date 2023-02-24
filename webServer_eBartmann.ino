#include <SPI.h>
#include <Ethernet.h>
 
byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0xB3, 0xEA};
 
IPAddress ip(192, 168, 178, 21);

// Ethernet Library als Server initialisieren:
EthernetServer meinServer(80);  // Port 80: Web-Server
 
void setup() {
  // Ethernet Verbindung und Server starten:
  Ethernet.begin(mac, ip);
  meinServer.begin();
}
 
void loop() {
  EthernetClient meinClient = meinServer.available();
  // Wenn es einen Client gibt, dann...
  if(meinClient) {
    meinClient.println("HTTP/1.1 200 OK");
    meinClient.println("Content-Type: text/html");
    meinClient.println();
    meinClient.println("<html>\n<head><title>Arduino Web-Server</title></head>\n<body>");
    meinClient.print("<h3>Hallo Welt</h3>");
    meinClient.println("</body>\n</html>");
  }
  delay(1);               // kurze Pause fuer Web-Browser
  meinClient.stop();
 }
