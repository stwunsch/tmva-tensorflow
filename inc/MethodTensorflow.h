#ifndef ROOT_TMVA_METHODTENSORFLOW
#define ROOT_TMVA_METHODTENSORFLOW

#include <string>

#include "TMVA/MethodBase.h"

//#include "tensorflow/core/public/session.h"

namespace TMVA {

    class MethodTensorflow : public MethodBase {

    public:
        /*
        * Constructor for training and reading
        * @param jobName unkown
        * @param methodTitle title of the method
        * @param theData data which was added to the TMVA Factory
        * @param theOption options string passed by the user to this method
        * @param theTargetDir target directory in ROOT file which stores the information about the training
        */
        MethodTensorflow(const TString& jobName,
            const TString& methodTitle,
            DataSetInfo& theData,
            const TString& theOption = "",
            TDirectory* theTargetDir = 0);

        /*
        * Constructor for calculating graph output of previously trained graphs
        * @param theData data which should be classified
        * @param theWeightFile the xml file from which the method reads the weights
        * @param theTargetDir target directory in ROOT file which stores information about the training
        */
        MethodTensorflow(DataSetInfo& theData,
            const TString& theWeightFile,
            TDirectory* theTargetDir = 0);

        // Init the method
        void Init();

        // Train the model
        virtual void Train();

        // Process the options of the method
        void DeclareOptions();
        void ProcessOptions();

        // Classifier response
        Double_t GetMvaValue(Double_t* errLower = 0, Double_t* errUpper = 0);

        // Create ranking
        const Ranking* CreateRanking();

        // Print help message
	    void GetHelpMessage() const;

    protected:
        void AddWeightsXMLTo(void*) const;
        void ReadWeightsFromXML(void*);
		Bool_t HasAnalysisType(Types::EAnalysisType, UInt_t, UInt_t);


    protected:
        //tensorflow::Session* session;
        //tensorflow::GraphDef graph;
        std::string fFilepathGraph;

        ClassDef(TMVA::MethodTensorflow, 1)

    }; // class MethodTensorflow

} // namespace TMVA

#endif // ROOT_TMVA_METHODTENSORFLOW
