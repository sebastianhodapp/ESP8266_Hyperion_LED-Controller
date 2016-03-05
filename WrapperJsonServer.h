#ifndef WrapperJsonServer_h
#define WrapperJsonServer_h

#include "BaseHeader.h"
#include <ArduinoJson.h>
#include <WifiServer.h>
#include <WifiClient.h>

#define TCP_BUFFER 256

class WrapperJsonServer {
  public:
    WrapperJsonServer(uint16_t ledCount, uint16_t tcpPort);
    void
      begin(void),
      handle(void);

    void
      onLedColorWipe(void(* function) (byte, byte, byte)),
      onClearCmd(void(* function) (void));
  private:
    void
      handleConnection(boolean newClient),
      readData(void);
  
    void 
      ledColorWipe(byte r, byte g, byte b),
      (* ledColorWipePointer) (byte, byte, byte);
    void 
      clearCmd(void),
      (* clearCmdPointer) (void);
  
    WiFiServer _tcpServer;
    WiFiClient _tcpClient;
    
    uint16_t _ledCount;
    uint16_t _tcpPort;
};

#endif
