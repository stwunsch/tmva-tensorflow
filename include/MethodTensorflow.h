/******************************************************************************
 * Stefan Wunsch, 2016                                                        *
 *                                                                            *
 * TMVA plugin for loading and executing Tensorflow graphs/models.            *
 ******************************************************************************/

#ifndef ROOT_TMVA_METHODTENSORFLOW
#define ROOT_TMVA_METHODTENSORFLOW

#include <TMVA/MethodBase.h>

namespace TMVA{

    class MethodTensorflow : public MethodBase {

    public:
        /**
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

        /**
        * Constructor for calculating graph output of previously trained graphs
        * @param theData data which should be classified
        * @param theWeightFile the xml file from which the method reads the weights
        * @param theTargetDir target directory in ROOT file which stores information about the training
        */
        MethodTensorflow(DataSetInfo& theData,
            const TString& theWeightFile,
            TDirectory* theTargetDir = NULL);

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

    protected:
        void AddWeightsXMLTo(void* parent) const;
        void ReadWeightsFromXML(void* wghtnode);
        void ReadWeightsFromStream(std::istream&); // backward compatibility

    }; // class MethodTensorflow

} // namespace TMVA

#endif // ROOT_TMVA_METHODTENSORFLOW
