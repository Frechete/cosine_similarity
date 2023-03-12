#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



double cosine_dist(
    std::vector<double> &vec_a,
    std::vector<double> &vec_b,
    size_t vec_size) {
    double a_dot_b = 0.0;
    double a_mag = 0;
    double b_mag = 0;
    for (size_t i = 0; i < vec_size; ++i)
    {
        a_dot_b += (vec_a[i]*vec_b[i]);
        a_mag += (vec_a[i]*vec_a[i]);
        b_mag += (vec_b[i]*vec_b[i]);
    }
    double dist = 1.0 - (a_dot_b / (sqrt(a_mag) * sqrt(b_mag)));
    return dist;
}

/*
 * Complete the 'cosine_similarity' function below.
 *
 * The function is expected to return a DOUBLE.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a_keys
 *  2. DOUBLE_ARRAY a_values
 *  3. INTEGER_ARRAY b_keys
 *  4. DOUBLE_ARRAY b_values
 */

double cosine_similarity(vector<int> a_keys, vector<double> a_values, vector<int> b_keys, vector<double> b_values) {
    int numbers_a = a_keys.back();
    int numbers_b = b_keys.back();
    int max = numbers_a>numbers_b?numbers_a:numbers_b;
    std::vector<double> vector1(max, 0.0);
    std::vector<double> vector2(max, 0.0);
    unsigned int a_vecSize = a_keys.size();
    for(unsigned int i = 0; i < a_vecSize; i++) {
    vector1[a_keys[i]] = a_values[i];
    }
    unsigned int b_vecSize = b_keys.size();
    for(unsigned int i = 0; i < b_vecSize; i++) {
    vector2[b_keys[i]] = b_values[i];
    }
    
    return cosine_dist(vector1, vector2, max);
    
}


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

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
