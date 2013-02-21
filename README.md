### cantata native application

How to launch cantata-native application to a tizen target:

### Prerequisites (Unix only):
    * Tizen SDK version 2.0 or higher

### Launch cantata native application using CLI:
    Noy supported yet
    
### Launch cantata native application using eclipse (Ubuntu only):
1. getting sources

    $ git clone https://github.com/yoonky/cantata-native.git
    
    $ git clone https://github.com/yoonky/cantata-web.git
    
    $ git clone https://github.com/yoonky/cantata-jsbind.git
    
    $ git clone https://github.com/yoonky/cantata-node.git


2. Setting projects on eclipse

    1. integrate cantata-web project to cantata-native
    
      cp ./cantata-web/* ./cantata-native/res/ -R
      
    2. install node to cantata-native project
    
      $ cd cantata-node
 
      $ mkdir output
 
      $ ./build --dest-cpu=x86 --with-shared --prefix=./output
 
      $ cp ./output/node ../cantata-native/res/libnode.so

    3. import cantata-native and cantata-jsbind project to your Tizen IDE
    
    4. in case cantata-jsbind, add include path: C/C++ build > Settings > Tool Settings > C++ Compiler > Includes

      ~/your working directory/cantata-node/node/src

      ~/your working directory/cantata-node/node/deps/uv/include

      ~/your working directory/cantata-node/node/deps/v8/include

    5. build cantata-jsbind project
      tizen-native.node file will be generated on the build configuration folder
      
      copy tizen-native.node to cantata-native's res/routes folder
    
    
3. Launch project

     build cantata-native project and run the project
     
     click "Start service"
     
     $ sdb forward tcp:3000 tcp:3000
     
     connect to localhost:3000 with your browser




