#include "PhoneDirectory.h"
int main(){
PhoneDirectory pd;
pd.loadData("sample_data.txt");
pd.menu();
return 0;
}
