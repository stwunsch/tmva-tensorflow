#include <iostream>
#include <string>
#include <vector>

#include "tensorflow/core/public/session.h"

int main(){
    std::cout << "Test" << std::endl;

    std::string graph_file_name = "blub.pb";
    std::cout << "Load graph: " << graph_file_name << std::endl;

    // Load graph
    tensorflow::GraphDef graph;
    tensorflow::ReadBinaryProto(tensorflow::Env::Default(), graph_file_name, &graph);

    // This example uses the default options which connects
    // to a local runtime.
    tensorflow::SessionOptions options;
    std::unique_ptr<tensorflow::Session> session(tensorflow::NewSession(options));

    // Create the session with this graph.
    tensorflow::Status s = session->Create(graph);
    if (!s.ok()) { std::cout << "Sth went wrong!" << std::endl; }
    else std::cout << "Session is created!" << std::endl;

    // Run session
    //session->Run();

    // Close the session to release the resources associated with
    // this session.
    session->Close();
}
