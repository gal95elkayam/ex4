//
// Created by gal on 09/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler{
public:
    /**
     * Handles the client
     * @param inputStream input stream which contains the clients's message
     * @param outputStream output stream which we will write our answer in
     */
    virtual void handleClient(int newsockfd) = 0;
};
#endif //EX4_CLIENTHANDLER_H