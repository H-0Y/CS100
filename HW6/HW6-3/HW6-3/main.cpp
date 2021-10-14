//
//  main.cpp
//  HW6-3
//
//  Created by Apple on 2019/12/4.
//  Copyright © 2019 huangly. All rights reserved.
//

#include "gechatuser.h"
#include <iostream>

int main() {
    shared_ptr<GechatUser> gzw(new GechatUser("GeziWang")); shared_ptr<GechatUser> gf(new GechatUser("Girlfriend")); gzw->addFriend(gf);
    gf->addFriend(gzw);
    gf->doubleDelete(gzw);
    CustomSet<GechatUser> sad_story;
    sad_story.add(*gzw);
    sad_story.add(*gf);
    sad_story.printSet();
    // prints "{GeziWang (friends: 0), Girlfriend (friends: 0)}\n"
}
