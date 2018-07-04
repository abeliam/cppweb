#include "cppweb/RouteTree.hpp"
#include <iostream>

cppweb::RouteTree::RouteTree() {

}

cppweb::RouteTree::RouteTree(RouteCollection routes) {
    std::vector<char> buffer;
    Node * node;
    for(auto it  = routes.begin(); it != routes.end(); ++it) {
        node = &root;
        std::string path = it->path;
        for(auto path_it = path.begin(); path_it != path.end(); ++path_it) {
            if (*path_it != '/') {
                buffer.push_back(*path_it);
            }
            std::string subpath(buffer.begin(), buffer.end());
            if (*path_it == '/' || &(*path_it) == &path[path.size()-1]) {
                if(!node->hasChild(subpath)) {
                    if (&(*path_it) == &path[path.size()-1]) {
                        node->addChild(subpath,
                            new RouteNode(
                                &(*it)
                            )
                        );
                    }
                    else {
                        node->addChild(subpath,
                            new RouteNode()
                        );
                    }
                }
                node = node->child(subpath);
                buffer.clear();
            }
        }
    }
}
