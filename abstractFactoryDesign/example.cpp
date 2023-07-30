#include<bits/stdc++.h>
using namespace std;

class Ibutton {
    public: 
        virtual void click() = 0;
};

class WinButton: public Ibutton {
    public:
        void click() {
            cout<<"windows button created."<<endl;
        }
};

class MacButton: public Ibutton {
    public:
        void click() {
            cout<<"Mac button created."<<endl;
        }
};

class ITextBox {
    public: 
        virtual void write() = 0;
};


class WinTextBox: public ITextBox {
    public:
        void write() {
            cout<<"windows textbox created."<<endl;
        }
};

class MacTextBox: public ITextBox {
    public:
        void write() {
            cout<<"Mac textbox created."<<endl;
        }
};

class IFactory {
    public:
        virtual Ibutton* createButton() = 0;
        virtual ITextBox* createTextBox() = 0;

};

class MacFactory: public IFactory {
    public:
        Ibutton *createButton() {
            return new MacButton();
        }
        ITextBox *createTextBox() {
            return new MacTextBox();
        }
};


class WinFactory: public IFactory {
    public:
        Ibutton *createButton() {
            return new WinButton();
        }
        ITextBox *createTextBox() {
            return new WinTextBox();
        }
};

class GuiFactory {
    public:
        static IFactory* getFactory(string osType) {
            if(osType == "windows") {
                return new WinFactory();
            } else {
                return new MacFactory();
            }
        }
};




int main() {
    string osType;
    cin>>osType;
    IFactory *factory = GuiFactory::getFactory(osType);
    Ibutton *button = factory->createButton();
    button->click();

    ITextBox *textBox = factory->createTextBox();
    textBox->write();



    return 0;
}