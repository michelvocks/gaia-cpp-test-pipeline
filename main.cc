#include "cppsdk/sdk.h"
#include <list>
#include <iostream>

void testjob(std::list<gaia::argument> args) throw(string) {
    std::cout << "Test job has been triggered!" << std::endl;
}

int main() {
    std::list<gaia::job> jobs;
    gaia::job j;
    j.handler = &testjob;
    j.description = "this is a test job";
    j.title = "testjob";
    jobs.push_back(j);

    // Serve
    try {
        gaia::Serve(jobs);
    } catch (string e) {
        std::cout << "Error: " << e << std::endl;
    }
}
