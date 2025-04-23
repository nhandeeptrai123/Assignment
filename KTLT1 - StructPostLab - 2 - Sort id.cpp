#include <iostream>
using namespace std; 
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};
SCP** sortDatabase(SCP** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - i - 1; j++) {
            if (arr[j] -> id > arr[j + 1] -> id) {
                int temp = arr[j] -> id; 
                arr[j] -> id = arr[j + 1] -> id;
                arr[j + 1] -> id = temp; 
            }
        }
    }
    return arr; 
}
int main () {
    int n = 6;
    SCP** data = new SCP* [n];
    data[0] = new SCP {2, 1, "SCP-002 is to remain connected to a suitable power supply at all times.", "SCP-002 resembles a tumorous, fleshy growth with a volume of roughly 60 cubed meter.", nullptr, 0};
    data[1] = new SCP {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", nullptr, 0};
    data[2] = new SCP {500, 0, "SCP-500 must be stored in a cool and dry place away from bright light.", "SCP-500 is a small plastic can which at the time of writing contains forty-seven (47) red pills.", nullptr, 0};
    data[3] = new SCP {49, 1, "SCP-049 is contained within a Standard Secure Humanoid Containment Cell in Research Sector-02 at Site-19.", "SCP-049 is a humanoid entity, roughly 1.9 meters in height, which bears the appearance of a medieval plague doctor.", nullptr, 0};
    data[4] = new SCP {1487, 1, "SCP-1487 is to be kept in Humanoid Containment Chamber #3821 at Site 23.", "SCP-1487 is a female humanoid of Filipino descent. The entity is fifteen (15) years old and measures 1.7m in height and 70kg in weight.", nullptr, 0};
    data[5] = new SCP {715, 0, "SCP-715 is to be contained at its point of origin within the ████████ City Mall in ████████, Ohio.", "SCP-715 is a \"Take Your Own Photo\" fotomat model photo booth manufactured by the Sony corporation in 1972.", nullptr, 1};
    
    data = sortDatabase(data, n);
    
    cout << data[2]->description;
    
    for (int i = 0; i < n; i++) {
        delete [] data[i]->addendums;
        delete data[i];
    }
    delete [] data;
}