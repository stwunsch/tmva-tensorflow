void TMVAUsage(){
    /*
     * Setup
     */

    // This loads the library
    TMVA::Tools::Instance();

    /*
     * Read training and test data
     */

    // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
    TString fname = "./tmva_class_example.root";
    if(gSystem->AccessPathName( fname )){ // file does not exist in local directory
        gSystem->Exec("curl -O http://root.cern.ch/files/tmva_class_example.root");
    }
    TFile *input = TFile::Open(fname);

    // Get training and test trees
    TTree *signal     = (TTree*)input->Get("TreeS");
    TTree *background = (TTree*)input->Get("TreeB");

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString outfileName("TMVA.root");
    TFile* outputFile = TFile::Open(outfileName, "RECREATE");

    // Create the TMVA factory
    TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
        "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );

    // Load the data
    TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");

    dataloader->AddVariable("myvar1 := var1+var2", 'F');
    dataloader->AddVariable("myvar2 := var1-var2", "Expression 2", "", 'F');
    dataloader->AddVariable("var3", "Variable 3", "units", 'F');
    dataloader->AddVariable("var4", "Variable 4", "units", 'F');
    dataloader->AddSpectator("spec1 := var1*2", "Spectator 1", "units", 'F');
    dataloader->AddSpectator("spec2 := var1*3", "Spectator 2", "units", 'F');

    Double_t signalWeight = 1.0;
    Double_t backgroundWeight = 1.0;
    dataloader->AddSignalTree(signal, signalWeight);
    dataloader->AddBackgroundTree(background, backgroundWeight);

    dataloader->SetBackgroundWeightExpression("weight");
    TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
    TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";
    dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
        "nTrain_Signal=1000:nTrain_Background=1000:SplitMode=Random:NormMode=NumEvents:!V" );

    /*
     * Book methods and train/evaluate them
     */

    // Book methods
    factory->BookMethod( dataloader, TMVA::Types::kFisher, "Fisher",
        "H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );
    factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT",
        "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

    // Train MVAs using the set of training events
    factory->TrainAllMethods();

    // ---- Evaluate all MVAs using the set of test events
    factory->TestAllMethods();

    // ----- Evaluate and compare performance of all configured MVAs
    factory->EvaluateAllMethods();

    /*
     * Clean-up
     */

    // Save the output
    outputFile->Close();
    delete factory;
    delete dataloader;

    /*
     * Launch GUI
     */

     TMVA::TMVAGui(outfileName);
}
