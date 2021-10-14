//
//  image_io.hpp
//  HW7
//
//  Created by Apple on 2019/12/14.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef image_io_hpp
#define image_io_hpp

#include <stdlib.h>

#include <string>
#include "types.hpp"
using namespace std;
using namespace Eigen;

Image loadImage( const std::string & pathToRaw );
void saveImage( Image & img, const std::string & pathToRaw );

#endif /* image_io_hpp */
