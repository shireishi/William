# William
This project will run as a subprocess and will primarily manage the technology linked to its systems
using a custom-made network API that will communicate intention and execution information over a TCP
protocol.

## Configuration
```json
// Elara's Room config file
{
    "name":"Elara's Room",
    "type":"light",
    "default":"off",
    "action":"on",
    "possible":[
        "off",
        "on"
    ],
    "address":"192.168.0.27",
    "port":"8080"
},
{
    "name":"Elara's Computer",
    "type":"computer",
    "default":"off",
    "action":"on",
    "possible":[
        "off",
        "on",
        "sleep",
        "reset"
    ],
    "address":"192.168.0.21",
    "port":"8080"
}
```
This configuration file will hold all of the necessary information to control the device which is registered.