#include "MethodTensorflow.h"

namespace TMVA{

    void MethodTensorflow::Init(){
    }

    void MethodTensorflow::Train(){
    }

    void MethodTensorflow::DeclareOptions(){
    }

    void MethodTensorflow::ProcessOptions(){
    }

    Double_t MethodTensorflow::GetMvaValue(Double_t*, Double_t*){
        return 0;
    }

    const Ranking* MethodTensorflow::CreateRanking(){
        Log() << kWARNING << "Creating a ranking is not yet implemented." << Endl;
        return 0;
    }

    void MethodTensorflow::AddWeightsXMLTo(void* parent) const{
    }

    void MethodTensorflow::ReadWeightsFromXML(void* wghtnode){
    }

    void MethodTensorflow::ReadWeightsFromStream(std::istream&){
        Log() << kERROR << "Dont' use this option!" << Endl;
    }

} // namespace TMVA
