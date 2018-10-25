
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

enum signedEnum {signedE,unsignedE};
enum typeQualE {constQ,volatileQ,bothQ};
enum storageSpecE {autoS,registerS,staticS,externS,typedefS};
enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS};
enum paramType {signedPT,typeQualPT,typeSpecSP};

class ASTnode {
private:
    std::string production; 
//    std::list <int []> param;
public:
    ASTnode(){

    }
};


class whileNode : public ASTnode {

};

class forNode : public ASTnode {

};

class functionNode : public ASTnode {

};

class typeNode : public ASTnode {

};

class ifNode : public ASTnode {

};
