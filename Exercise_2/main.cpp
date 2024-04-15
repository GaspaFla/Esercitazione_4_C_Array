#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
using namespace std;

int main()
{
    char c;
    ifstream file("data.csv");
    if(file.fail()){
        cerr<<"file not found"<<endl;
        return 404;
    }
    string line;
    getline(file, line);
    istringstream convertStr(line);
    double S;
    convertStr >>c>>c>>S ;
    getline(file, line);
    istringstream convertStr1(line);
    int n;
    convertStr1>>c>>c>>n ;
    getline(file, line);
    double *pv1 =new double[n];
    double *pv2=new double[n];
    double x;

    //salvo le mie condizioni iniziali

    ios init(NULL);
    init.copyfmt(cout);


    ofstream ofs("result.txt");
    cout<<fixed;
    ofs<<fixed;
    cout.precision(2);
    ofs.precision(2);
    ofs<<"S = "<<S<<", n = "<<n<<endl;
    cout<<"S = "<<S<<", n = "<<n<<endl;

    //ripristino le condizioni a quelle iniziali

    cout.copyfmt(init);
    ofs.copyfmt(init);


    cout<<"w = [ ";
    ofs<<"w = [ ";
    for (int i=0; i<n; i++){
        getline(file,line);
        istringstream convertStra(line);
        convertStra >> x;
        cout<<x<<" ";
        ofs<<x<<" ";
        (pv1[i])=x;
        convertStra >>c>> x;
        (pv2[i])=x;
    }
    cout<<"]"<<endl;
    cout<<"r = [ ";
    ofs<<"]"<<endl;
    ofs<<"r = [ ";
    for (int i=0; i<n; i++){
        cout<<(pv2[i])<<" ";
        ofs<<(pv2[i])<<" ";

    }
    cout<<"]"<<endl;
    ofs<<"]"<<endl;

    double risultato=prodottoscalarepesato (pv1,pv2,n,S);
    double tassoTotale= (risultato/S)-1;


    cout<<"Rate of return of the portfolio: "<<tassoTotale<<endl;
    ofs<<"Rate of return of the portfolio: "<<tassoTotale<<endl;

    cout<<fixed;
    ofs<<fixed;
    cout.precision(2);
    ofs.precision(2);

    cout<<"V: "<<risultato;
    ofs<<"V: "<<risultato;
    delete (pv1);
    delete(pv2);
    file.close();
    ofs.close();




  return 0;
}

