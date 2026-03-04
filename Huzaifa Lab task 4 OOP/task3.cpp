//Name:Huzaifa Mujtaba
//Roll no:25P-0694
//section:BCS-2C
#include <iostream>
using namespace std;
struct CircleShape {         
    float centerX;      
    float centerY;            
    float radius;
    float calc_area(CircleShape data){     
        float computedArea = 3.147 * data.radius * data.radius;  
        return computedArea;
    }
    void grow(CircleShape& data, float factor){ 
        data.radius *= factor;
    }
    void translate(CircleShape& data, float shiftX, float shiftY) { 
        data.centerX += shiftX;
        data.centerY += shiftY;
    }
    void outP(CircleShape data, float computedArea) { 
        cout << "Circle Radius: " << data.radius 
             << " With Center (" << data.centerX 
             << " , " << data.centerY << ")" << endl;
        cout << "Area is: " << computedArea << endl;
    }
};
int main() {
    float areaValue;              
    CircleShape obj1;         
    cout << "Enter initial X position of circle: ";
    cin >> obj1.centerX;
    cout << "Enter initial Y position of circle: ";
    cin >> obj1.centerY;
    cout << "Enter Radius of the circle: ";
    cin >> obj1.radius;
    areaValue = obj1.calc_area(obj1);
    obj1.outP(obj1, areaValue);
    cout << endl << "Do you want to translate the circle? (Y/N): ";
    char choiceTranslate;        
    cin >> choiceTranslate;
    if(choiceTranslate == 'Y' || choiceTranslate == 'y') {
        cout << "Enter new x position: ";
        int shiftValueX;       
        cin >> shiftValueX;
        cout << "Enter new y position: ";
        int shiftValueY;        
        cin >> shiftValueY;
        obj1.translate(obj1, shiftValueX, shiftValueY);
    }
    cout << endl << "Do you want to increase the radius of the circle? (Y/N): ";
    char choiceGrow;         
    cin >> choiceGrow;
    if(choiceGrow == 'Y' || choiceGrow == 'y') {
        cout << "Enter factor to increase the radius: ";
        int growthFactor;     
        cin >> growthFactor;
        obj1.grow(obj1, growthFactor);
    }
    areaValue = obj1.calc_area(obj1);
    obj1.outP(obj1, areaValue);
    return 0;
}