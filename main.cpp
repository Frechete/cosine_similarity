int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_keys_count_temp;
    getline(cin, a_keys_count_temp);

    int a_keys_count = stoi(ltrim(rtrim(a_keys_count_temp)));

    vector<int> a_keys(a_keys_count);

    for (int i = 0; i < a_keys_count; i++) {
        string a_keys_item_temp;
        getline(cin, a_keys_item_temp);

        int a_keys_item = stoi(ltrim(rtrim(a_keys_item_temp)));

        a_keys[i] = a_keys_item;
    }

    string a_values_count_temp;
    getline(cin, a_values_count_temp);

    int a_values_count = stoi(ltrim(rtrim(a_values_count_temp)));

    vector<double> a_values(a_values_count);

    for (int i = 0; i < a_values_count; i++) {
        string a_values_item_temp;
        getline(cin, a_values_item_temp);

        double a_values_item = stod(ltrim(rtrim(a_values_item_temp)));

        a_values[i] = a_values_item;
    }

    string b_keys_count_temp;
    getline(cin, b_keys_count_temp);

    int b_keys_count = stoi(ltrim(rtrim(b_keys_count_temp)));

    vector<int> b_keys(b_keys_count);

    for (int i = 0; i < b_keys_count; i++) {
        string b_keys_item_temp;
        getline(cin, b_keys_item_temp);

        int b_keys_item = stoi(ltrim(rtrim(b_keys_item_temp)));

        b_keys[i] = b_keys_item;
    }

    string b_values_count_temp;
    getline(cin, b_values_count_temp);
    b_values_count_temp.erase(b_values_count_temp.find_last_not_of(" \n\r\t")+1);

    int b_values_count = stoi(ltrim(rtrim(b_values_count_temp)));

    vector<double> b_values(b_values_count);

    for (int i = 0; i < b_values_count; i++) {
        string b_values_item_temp;
        getline(cin, b_values_item_temp);

        double b_values_item = stod(ltrim(rtrim(b_values_item_temp)));

        b_values[i] = b_values_item;
    }

   double result = cosine_similarity(a_keys, a_values, b_keys, b_values);
   cout << "Cosine similarity: " << result << endl;

   return 0;
}

double cosine_similarity(vector<int> a_keys, vector<double> a_values, vector<int> b_keys, vector<double> b_values) {
   int numbers_a = *max_element(a_keys.begin(),a_keys.end());
   int numbers_b = *max_element(b_keys.begin(),b_keys.end());
   int max_num=numbers_a>numbers_b?numbers_a:numbers_b;

   std::vector<double> vector1(max_num+1);
   std::vector<double> vector2(max_num+1);
   
   for(unsigned int i=0;i<a_vals.size();i++){
       vector1[a_vals[i].first]=a_vals[i].second;
   }
   
   for(unsigned int j=0;j<b_vals.size();j++){
       vector2[b_vals[j].first]=b_vals[j].second;
   }
   
   double dot_product=0.0,magnitude_a=0.0,magnitude_b=0.0;

   for(int k=1;k<=max_num;k++){
       dot_product+=vector1[k]*vector2[k];
       magnitude_a+=pow(vector1[k],2);
       magnitude_b+=pow(vector2[k],2);
   }
   
   magnitude_a=sqrt(magnitude_a);
   magnitude_b=sqrt(magnitude_b);
   
   return dot_product/(magnitude_a*magnitude_b);
}
