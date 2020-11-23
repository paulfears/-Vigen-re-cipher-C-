#include <iostream>



string encrypt(string data, string key){
  int data_length = data.length();
  int key_length = key.length();
  string cyphor = "";
  string letters = "abcdefghijklmnopqrstuvwxyz 1234567890";
  for(int i =0; i<data_length; i++){
    int shift_ammount = letters.find(key[i%key_length]);
    cyphor += letters[(letters.find(data[i])+shift_ammount)%letters.length()];
  }
  
  return cyphor;
};


string decrypt(string cyphor, string key){
  int cyphor_length = cyphor.length();
  int key_length = key.length();
  string letters = "abcdefghijklmnopqrstuvwxyz 1234567890";
  string data = "";
  cout<<endl<<endl<<endl;
  for(int i = 0; i<cyphor_length; i++){
    int shift_ammount = letters.find(key[i%key_length]);
    
    int index = letters.find(cyphor[i])-shift_ammount;
    if(index<0){
      index = letters.length()+index;
    }
    data += letters[index%letters.length()];
  }
  return data;
}

int main() {
  string messege = "attack at down";
  string key = "open seasime";

  string cyphor = encrypt(messege, key);
  cout<<cyphor<<endl;
  cout<<decrypt(cyphor, key)<<endl;
};