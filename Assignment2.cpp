#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;



int main(int argc, char** argv)
{
    string imageBase = string(argv[1]);
    string flag;

    if(argc == 2){

    }else if(argc > 2){
        flag = string(argv[2]);
        if(flag=="-d"){


        }else if(flag == "-x"){

        }
    }

    return 0;
}

class VolImage
{
private:// private members
    int width, height;// width and height of image stack
    std::vector<unsigned char**> slices;// data for each slice, in order
    string filename;
public:// public members
    VolImage(){
        width = 0;
        height = 0;

    }// default constructor - define in .cpp
    ~VolImage(){

    }// destructor - define in .cpp file

    // populate the object with images in stack and
    //set member variables define in .cpp
bool readImages(std::string baseName){

    string widthS,heightS,numImagesS;
    int numImages;
    filename = baseName + ".data";
	string line;
	string text;

	// Open file with a file stream. ifstream constructor
	// wants a C char * string, so call c_str() method.
	ifstream in(filename.c_str());

	if(!in)
		{ cout << "Couldn't open " << filename << endl; }
	else
		{
		while( getline(in,line))
		{
			text = "";
			istringstream iss(line);
			vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
			widthS =results.at(0);
			heightS=results.at(1);
			numImagesS=results.at(2);
			istringstream Wiss(widthS);
			Wiss>>width;
			istringstream Hiss(heightS);
			Hiss>>height;
			istringstream Niss(numImagesS);
			Niss>>numImages;
			cout << width <<" "<<height<<" "<<numImages<<endl;
		}
        in.close();
        }

        for(int j = 0; j < numImages; j++){
            unsigned char ** image = new unsigned char *[height];
            for(int i = 0; i<height; i++){
                unsigned char * row = new unsigned char [width];
                image[i] = row;
            }
            slices.push_back(image);
        }

        for(int imageNum = 0; imageNum < numImages; imageNum++){
            filename = baseName + imageNum + ".raw";
            ifstream fin(filename.c_str());
            for(int i = 0; i<height; i++){

            }
        }

    }


    // compute difference map and write out;  define in .cpp
    void diffmap(int sliceI, int sliceJ, std::string output_prefix);// extract slice sliceId and write to output - define in .cpp

    void extract(int sliceId, std::string output_prefix);
    // number of bytes uses to store image data bytes
    //and pointers (ignore vector<> container, dims etc)
    int volImageSize(void);// define in .cpp



    };
