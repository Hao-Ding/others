# Content
This is the basic code about how to use OpenSSL and Mini-XML.

# How to make the programs work?

First, install OpenSSL and Mini-XML, then compile the test code.

gcc -o client client.c -lssl -lcrypto -lmxml -lpthread

gcc -o server server.c -lssl -lcrypto -lmxml -lpthread

At last, run them:

./server 7838 5 cacert.pem privkey.pem

./client 127.0.0.1 7838 25(min) 30(max)

# How to generate certificate and private key?

openssl genrsa -out privkey.pem 2048
openssl req -new -x509 -key privkey.pem -out cacert.pem -days 1095
