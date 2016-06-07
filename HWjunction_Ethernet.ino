
#include <SPI.h>
#include <Ethernet.h>


// Configure LED pin
int led = 7 ;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
IPAddress ip(192,168,43,96);                    // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 192, 168, 43, 1 };                   // internet access via router
byte subnet[] = { 255,255,0,0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
    // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}


void loop() {
  // Create a client connection
  int sensorValue = analogRead(A0);
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
         }

         //if HTTP request has ended
         if (c == '\n') {          
           Serial.println(readString); //print to serial monitor for debuging
     
           client.println("HTTP/1.1 200 OK"); //send new page
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<TITLE>HWjunction</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>HWjunction Program: Ethernet Control</H1>");
           client.println("<hr />");
           client.println("<br />");  
           client.println("<H2>Controls</H2>");
           client.println("<br />");  
           client.println("<a href=\"/?button1on\"\">Turn On </a>");
           client.println("<a href=\"/?button1off\"\">Turn Off</a><br />");   
           client.println("<br />");     
           client.println("<br />"); 
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //stopping client
           client.stop();
           //controls the Arduino if you press the buttons
           if (readString.indexOf("?button1on") >0){
               digitalWrite(led, HIGH);
           }
           if (readString.indexOf("?button1off") >0){
               digitalWrite(led, LOW);
           }

            //clearing string for next read
            readString="";  
           
         }
       }
    }
}
}
