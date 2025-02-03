#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram; 
    int rom;
    int storage;
public:
    void setCompany(string comp) {
        company = comp;}
    void setModel(string mod) {
        model = mod;}
    void setDisplayResolution(string resolution) {
        displayResolution = resolution;}
    void setRam(int memory) {
        ram = memory;}
    void setRom(int memory) {
        rom = memory;}
    void setStorage(int space) {
        storage = space;}
    string getCompany() {
        return company;}
    string getModel() {
        return model;}
    string getDisplayResolution() {
        return displayResolution;}
    int getRam() {
        return ram;}
    int getRom() {
        return rom;}
    int getStorage() {
        return storage;}
    void makePhoneCall() {
        cout << "Making a phone call..." << endl;}
    void sendMessage() {
        cout << "Sending a message..." << endl;}
    void connectToWifi() {
        cout << "Connecting to Wi-Fi..." << endl;}
    void browseInternet() {
        cout << "Browsing the internet..." << endl;}
    void displayAttributes() {
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Display Resolution: " << displayResolution << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "ROM: " << rom << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;}
};
int main() {
    Smartphone phone1;
    Smartphone phone2;
    phone1.setCompany("Apple");
    phone1.setModel("iPhone 14");
    phone1.setDisplayResolution("123x321");
    phone1.setRam(2);
    phone1.setRom(12);
    phone1.setStorage(25);
    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy S23");
    phone2.setDisplayResolution("2x1");
    phone2.setRam(8);
    phone2.setRom(256);
    phone2.setStorage(510);
    cout << "Phone 1 attributes:" << endl;
    phone1.displayAttributes();
    cout << endl;
    cout << "Phone 2 attributes:" << endl;
    phone2.displayAttributes();
    cout << endl;
    cout << "Actions with Phone 1:" << endl;
    phone1.makePhoneCall();
    phone1.sendMessage();
    phone1.connectToWifi();
    phone1.browseInternet();
    cout << endl;
    cout << "Actions with Phone 2:" << endl;
    phone2.makePhoneCall();
    phone2.sendMessage();
    phone2.connectToWifi();
    phone2.browseInternet();
    return 0;
}
