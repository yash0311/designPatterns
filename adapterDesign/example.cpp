#include<bits/stdc++.h>
using namespace std;

class XMLData {
    private:
        string data;
    public:
        XMLData(string data) {
            this->data = data;
        }
        string getData() {
            return data;
        }
};

class DataAnalyticsTool {
    private:
        string jsonData;
    public:
        DataAnalyticsTool() {

        }
        DataAnalyticsTool(string data) {
            this->jsonData = data;
        }
        virtual void analyse() {
            cout<<"analysing json data "<<jsonData<<endl;
        }
        void setJsonData(string data) {
            this->jsonData = data;
        }
};

class Adapter: public DataAnalyticsTool {
    private: 
        XMLData *xmlData;
    public:
        Adapter(XMLData *data) {
            this->xmlData = data;
        }
        string convertXmlToJson(XMLData *XMLData) {
            cout<<"converting xml data to json here..."<<endl;
            return xmlData->getData();
        }
        void analyse() override {
            string convertedJson = convertXmlToJson(this->xmlData);
            setJsonData(convertedJson);
            DataAnalyticsTool::analyse();
        }
};

class Client{
    public:
        void processData(DataAnalyticsTool *tool) {
            tool->analyse();
        }
};

int main () {
    // client accepts data analytics tool to analyse data
    // issue is that tool accepts data in json but we have XMLData
    // to overcome this issue we use adapter desing pattern
    XMLData *xmlData = new XMLData("sample xml data");
    // DataAnalyticsTool *tool = new DataAnalyticsTool(Json data missing) // here is the problem, we don't have json data
    DataAnalyticsTool *tool = new Adapter(xmlData);
    Client *client = new Client();
    client->processData(tool);
    return 0;
}