#include "MethodTensorflow.h"

namespace TMVA{

    void MethodTensorflow::Init(){
        // Load the graph
        Log() << kERROR << "Input graph: " << filepathInputGraph << Endl;
    }

    void MethodTensorflow::Train(){
    }

    void MethodTensorflow::DeclareOptions(){
        DeclareOptionRef(filepathInputGraph="foo.pb", "filepathInputGraph", "Path to file which contains input graph");
    }

    void MethodTensorflow::ProcessOptions(){
    }

    Double_t MethodTensorflow::GetMvaValue(Double_t*, Double_t*){
        return 0;
    }

    const Ranking* MethodTensorflow::CreateRanking(){
        Log() << kWARNING << "Creating a variable ranking is not yet implemented." << Endl;
        return 0;
    }

    void MethodTensorflow::AddWeightsXMLTo(void* parent) const{
    }

    void MethodTensorflow::ReadWeightsFromXML(void* wghtnode){
    }

    void MethodTensorflow::ReadWeightsFromStream(std::istream&){
        Log() << kERROR << "Don't use this option, it's deprecated!" << Endl;
    }

} // namespace TMVA
