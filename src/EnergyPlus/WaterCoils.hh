#ifndef WaterCoils_hh_INCLUDED
#define WaterCoils_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/FArray1A.hh>
#include <ObjexxFCL/FArray1S.hh>
#include <ObjexxFCL/FArray2A.hh>
#include <ObjexxFCL/Optional.hh>

// EnergyPlus Headers
#include <EnergyPlus.hh>
#include <DataGlobals.hh>

namespace EnergyPlus {

namespace WaterCoils {

	// Using/Aliasing

	// Data
	//PRIVATE ! Everything private unless explicitly made public

	//MODULE PARAMETER DEFINITIONS

	extern int const MaxPolynomOrder;
	extern int const MaxOrderedPairs;

	extern Real64 const PolyConvgTol;
	extern Real64 const MinWaterMassFlowFrac;
	extern Real64 const MinAirMassFlow;

	// coil types in this module
	extern int const WaterCoil_SimpleHeating;
	extern int const WaterCoil_DetFlatFinCooling;
	extern int const WaterCoil_Cooling;

	extern int const CoilType_Cooling;
	extern int const CoilType_Heating;

	extern int const CoilModel_Simple;
	extern int const CoilModel_Cooling;
	extern int const CoilModel_Detailed;

	// Parameters for Heat Exchanger Configuration
	extern int const CounterFlow;
	extern int const CrossFlow;
	extern int const SimpleAnalysis;
	extern int const DetailedAnalysis;

	//Water Systems
	extern int const CondensateDiscarded; // default mode where water is "lost"
	extern int const CondensateToTank; // collect coil condensate from air and store in water storage tank

	//Parameters for COIL:Water:SimpleHeating Coil Performance Input Method
	extern int const UAandFlow; // for Coil Performance Input Method = UA and Design Water Flow Rate
	extern int const NomCap; // for Coil Performance Input Method = Nominal Capacity

	// Parameters Subroutine CoolingCoil: design calc or simulation calc.
	extern int const DesignCalc; // ignore on/off check in CoolingCoil
	extern int const SimCalc; // pay attention to on/off check in CoolingCoil

	// DERIVED TYPE DEFINITIONS

	//MODULE VARIABLE DECLARATIONS:
	extern int NumWaterCoils; // The Number of WaterCoils found in the Input
	extern FArray1D_bool MySizeFlag;
	extern FArray1D_bool MyUAAndFlowCalcFlag;
	extern FArray1D_bool MyCoilDesignFlag;
	extern FArray1D_bool CoilWarningOnceFlag;
	extern FArray1D_int WaterTempCoolCoilErrs; // error counting for detailed coils
	extern FArray1D_int PartWetCoolCoilErrs; // error counting for detailed coils
	extern bool GetWaterCoilsInputFlag; // Flag set to make sure you get input once
	extern FArray1D_bool CheckEquipName;

	// Subroutine Specifications for the Module
	// Driver/Manager Routines

	// Get Input routines for module

	// Initialization routines for module

	// Algorithms for the module

	// Update routine to check convergence and update nodes

	// Reporting routines for module

	// Other routines

	// Types

	struct WaterCoilEquipConditions
	{
		// Members
		std::string Name; // Name of the WaterCoil
		std::string WaterCoilTypeA; // Type of WaterCoil ie. Heating or Cooling
		std::string WaterCoilModelA; // Type of WaterCoil ie. Simple, Detailed, etc.
		int WaterCoilType; // Type of WaterCoil ie. Heating or Cooling
		int WaterCoilModel; // Type of WaterCoil ie. Simple, Detailed, etc.
		int WaterCoilType_Num;
		std::string Schedule; // WaterCoil Operation Schedule
		int SchedPtr; // Pointer to the correct schedule
		bool RequestingAutoSize; // True if this coil has appropriate autosize fields
		Real64 InletAirMassFlowRate; // MassFlow through the WaterCoil being Simulated [kg/s]
		Real64 OutletAirMassFlowRate; // MassFlow throught the WaterCoil being Simulated[kg/s]
		Real64 InletAirTemp; // Inlet Air Temperature Operating Condition [C]
		Real64 OutletAirTemp; // Outlet Air Temperature Operating Condition [C]
		Real64 InletAirHumRat; // Inlet Air Humidity Ratio Operating Condition
		Real64 OutletAirHumRat; // Outlet Air Humidity Ratio Calculated Condition
		Real64 InletAirEnthalpy; // Inlet Air enthalpy [J/kg]
		Real64 OutletAirEnthalpy; // Outlet Air enthalpy [J/kg]
		Real64 TotWaterCoilLoad; // Total Load on the Coil [W]
		Real64 SenWaterCoilLoad; // Sensible Load on the Coil [W]
		Real64 TotWaterHeatingCoilEnergy; // Total Heating Coil energy of the Coil [J]
		Real64 TotWaterCoolingCoilEnergy; // Total Cooling Coil energy of the Coil [J]
		Real64 SenWaterCoolingCoilEnergy; // Sensible Cooling Coil energy of the Coil [J]
		Real64 DesWaterHeatingCoilRate; // Design Heating Coil Rate used for sizing [W]
		Real64 TotWaterHeatingCoilRate; // Total Heating Coil Rate on the Coil [W]
		Real64 DesWaterCoolingCoilRate; // Design Cooling Coil Rate used for sizing [W]
		Real64 TotWaterCoolingCoilRate; // Total Cooling Coil Rate on the Coil [W]
		Real64 SenWaterCoolingCoilRate; // Sensible Cooling Coil Rate on the Coil [W]
		Real64 UACoil; // WaterCoil UA Value
		Real64 LeavingRelHum; // Simple Coil Latent Model requires User input for leaving RH
		Real64 DesiredOutletTemp;
		Real64 DesiredOutletHumRat;
		Real64 InletWaterTemp; // Inlet Water Temperature [C]
		Real64 OutletWaterTemp; // Outlet Water Temperature [C]
		Real64 InletWaterMassFlowRate; // Inlet Water Mass Flow Rate [Kg/s]
		Real64 OutletWaterMassFlowRate; // Outlet Water Mass Flow Rate [Kg/s]
		Real64 MaxWaterVolFlowRate; // Maximum water Volume flow rate [m3/s]
		Real64 MaxWaterMassFlowRate; // Maximum water mass flow rate [Kg/s]
		Real64 InletWaterEnthalpy; // Inlet Water Enthalpy
		Real64 OutletWaterEnthalpy; // Outlet Water Enthalpy
		//These are the additional Geometry and Design Variables for Detailed Flat Fin Coil
		Real64 TubeOutsideSurfArea; // Tube Primary Surface Area
		Real64 TotTubeInsideArea; // Total Tube inside Surface Area
		Real64 FinSurfArea; // Fin Surface Area
		Real64 MinAirFlowArea;
		Real64 CoilDepth;
		Real64 FinDiam; // Fin Diameter or the Coil Height
		Real64 FinThickness;
		Real64 TubeInsideDiam; // Inner diameter of Tubes
		Real64 TubeOutsideDiam; // Outer Diameter of the Tubes
		Real64 TubeThermConductivity;
		Real64 FinThermConductivity;
		Real64 FinSpacing; // Fin Spacing or Distance
		Real64 TubeDepthSpacing;
		int NumOfTubeRows;
		int NumOfTubesPerRow;
		//BEGIN calculated parameters for detailed flat fin coil
		Real64 EffectiveFinDiam;
		Real64 TotCoilOutsideSurfArea;
		Real64 CoilEffectiveInsideDiam;
		Real64 GeometryCoef1;
		Real64 GeometryCoef2;
		FArray1D< Real64 > DryFinEfficncyCoef;
		Real64 SatEnthlCurveConstCoef;
		Real64 SatEnthlCurveSlope;
		Real64 EnthVsTempCurveAppxSlope;
		Real64 EnthVsTempCurveConst;
		Real64 MeanWaterTempSaved;
		Real64 InWaterTempSaved;
		Real64 OutWaterTempSaved;
		Real64 SurfAreaWetSaved;
		Real64 SurfAreaWetFraction;
		//END calculated parameters for detailed flat fin coil
		// Design Input Variables to the Design Detailed Simple inputs model
		Real64 DesInletWaterTemp; // Entering water temperature at Design(C)
		Real64 DesAirVolFlowRate; // Entering Air Volume Flow Rate Design( m3/s)
		Real64 DesInletAirTemp; // Entering air dry bulb temperature at Design(C)
		Real64 DesInletAirHumRat; // Entering air humidity ratio at design conditions
		Real64 DesTotWaterCoilLoad; // Total heat transfer rate at Design(Watt)
		Real64 DesSenWaterCoilLoad; // Sensible heat transfer rate at Design(Watt)
		//BEGIN calculated parameters for Design Detailed Simple inputs model
		Real64 DesAirMassFlowRate; // Design Air MassFlow through the WaterCoil [kg/Sec]
		Real64 UACoilTotal; // Overall external dry UA (W/C)
		Real64 UACoilInternal; // Overall internal UA(W/C)
		Real64 UACoilExternal; // Overall external heat transfer coefficient(W/C)
		Real64 UACoilInternalDes; // Overall design internal UA(W/C)
		Real64 UACoilExternalDes; // Overall design external heat transfer coefficient(W/C)
		Real64 DesOutletAirTemp; // Leaving air temperature at rating(C)
		Real64 DesOutletAirHumRat; // Humidity ratio of air leaving at design capacity.
		Real64 DesOutletWaterTemp; // Temp of Liquid Leaving the Coil at design Capacity
		int HeatExchType; // Heat exchanger configuration, default to Cross Flow
		int CoolingCoilAnalysisMode; // Mode Of analysis, Simple=1 and Detailed =2
		//    Simple= AllWet-AllDry, Detailed= PartWet-PartDry
		Real64 UACoilInternalPerUnitArea; // Internal overall heat transfer coefficient(W/m2 C)
		Real64 UAWetExtPerUnitArea; // External overall heat transfer coefficient(W/m2 C)
		Real64 UADryExtPerUnitArea; // External overall heat transfer coefficient(W/m2 C)
		Real64 SurfAreaWetFractionSaved; // Previous saved value, for numerical efficiency.
		//END calculated parameters for Design Inputs Detailed coil
		// variables for simple heating coil with variable UA
		Real64 UACoilVariable; // WaterCoil UA value when variable (simple heating coil only)
		Real64 RatioAirSideToWaterSideConvect; // "r" value for coil,
		Real64 AirSideNominalConvect; // nominal rating point air side convection term (fin_effic*(hc*A))
		Real64 LiquidSideNominalConvect; // nominal rating point water side convection term (hc*A)
		int Control; // Const Vol =1;  Variable Vol = 2
		int AirInletNodeNum;
		int AirOutletNodeNum;
		int WaterInletNodeNum;
		int WaterOutletNodeNum;
		int WaterLoopNum; // Plant loop index
		int WaterLoopSide; // Plant loop side index
		int WaterLoopBranchNum; // Plant loop branch index
		int WaterLoopCompNum; // Plant loop Comp index
		//begin variables for Water System interactions
		int CondensateCollectMode; // where does water come from
		std::string CondensateCollectName; // name of water source e.g. water storage tank
		int CondensateTankID; // index "pointer" to Storage TAnk array WaterStorage
		int CondensateTankSupplyARRID; // index pointe to supply Vdot array in WaterStorage
		Real64 CondensateVdot; // rate of water condensation from air stream [m3/s]
		Real64 CondensateVol; // amount of water condensed from air stream [m3]
		//end variables for water system interactions
		//COIL:Water:SimpleHeating Coil Performance Input Method
		int CoilPerfInpMeth; // 1 = UA and Design Water Flow Rate; 2 = Nominal Capacity
		Real64 FoulingFactor; // Coil fouling factor [m2K/W]

		// Default Constructor
		WaterCoilEquipConditions() :
			WaterCoilType( 0 ),
			WaterCoilModel( 0 ),
			WaterCoilType_Num( 0 ),
			SchedPtr( 0 ),
			RequestingAutoSize( false ),
			InletAirMassFlowRate( 0.0 ),
			OutletAirMassFlowRate( 0.0 ),
			InletAirTemp( 0.0 ),
			OutletAirTemp( 0.0 ),
			InletAirHumRat( 0.0 ),
			OutletAirHumRat( 0.0 ),
			InletAirEnthalpy( 0.0 ),
			OutletAirEnthalpy( 0.0 ),
			TotWaterCoilLoad( 0.0 ),
			SenWaterCoilLoad( 0.0 ),
			TotWaterHeatingCoilEnergy( 0.0 ),
			TotWaterCoolingCoilEnergy( 0.0 ),
			SenWaterCoolingCoilEnergy( 0.0 ),
			DesWaterHeatingCoilRate( 0.0 ),
			TotWaterHeatingCoilRate( 0.0 ),
			DesWaterCoolingCoilRate( 0.0 ),
			TotWaterCoolingCoilRate( 0.0 ),
			SenWaterCoolingCoilRate( 0.0 ),
			UACoil( 0.0 ),
			LeavingRelHum( 0.0 ),
			DesiredOutletTemp( 0.0 ),
			DesiredOutletHumRat( 0.0 ),
			InletWaterTemp( 0.0 ),
			OutletWaterTemp( 0.0 ),
			InletWaterMassFlowRate( 0.0 ),
			OutletWaterMassFlowRate( 0.0 ),
			MaxWaterVolFlowRate( 0.0 ),
			MaxWaterMassFlowRate( 0.0 ),
			InletWaterEnthalpy( 0.0 ),
			OutletWaterEnthalpy( 0.0 ),
			TubeOutsideSurfArea( 0.0 ),
			TotTubeInsideArea( 0.0 ),
			FinSurfArea( 0.0 ),
			MinAirFlowArea( 0.0 ),
			CoilDepth( 0.0 ),
			FinDiam( 0.0 ),
			FinThickness( 0.0 ),
			TubeInsideDiam( 0.0 ),
			TubeOutsideDiam( 0.0 ),
			TubeThermConductivity( 0.0 ),
			FinThermConductivity( 0.0 ),
			FinSpacing( 0.0 ),
			TubeDepthSpacing( 0.0 ),
			NumOfTubeRows( 0 ),
			NumOfTubesPerRow( 0 ),
			EffectiveFinDiam( 0.0 ),
			TotCoilOutsideSurfArea( 0.0 ),
			CoilEffectiveInsideDiam( 0.0 ),
			GeometryCoef1( 0.0 ),
			GeometryCoef2( 0.0 ),
			DryFinEfficncyCoef( 5, 0.0 ),
			SatEnthlCurveConstCoef( 0.0 ),
			SatEnthlCurveSlope( 0.0 ),
			EnthVsTempCurveAppxSlope( 0.0 ),
			EnthVsTempCurveConst( 0.0 ),
			MeanWaterTempSaved( 0.0 ),
			InWaterTempSaved( 0.0 ),
			OutWaterTempSaved( 0.0 ),
			SurfAreaWetSaved( 0.0 ),
			SurfAreaWetFraction( 0.0 ),
			DesInletWaterTemp( 0.0 ),
			DesAirVolFlowRate( 0.0 ),
			DesInletAirTemp( 0.0 ),
			DesInletAirHumRat( 0.0 ),
			DesTotWaterCoilLoad( 0.0 ),
			DesSenWaterCoilLoad( 0.0 ),
			DesAirMassFlowRate( 0.0 ),
			UACoilTotal( 0.0 ),
			UACoilInternal( 0.0 ),
			UACoilExternal( 0.0 ),
			UACoilInternalDes( 0.0 ),
			UACoilExternalDes( 0.0 ),
			DesOutletAirTemp( 0.0 ),
			DesOutletAirHumRat( 0.0 ),
			DesOutletWaterTemp( 0.0 ),
			HeatExchType( 0 ),
			CoolingCoilAnalysisMode( 0 ),
			UACoilInternalPerUnitArea( 0.0 ),
			UAWetExtPerUnitArea( 0.0 ),
			UADryExtPerUnitArea( 0.0 ),
			SurfAreaWetFractionSaved( 0.0 ),
			UACoilVariable( 0.0 ),
			RatioAirSideToWaterSideConvect( 1.0 ),
			AirSideNominalConvect( 0.0 ),
			LiquidSideNominalConvect( 0.0 ),
			Control( 0 ),
			AirInletNodeNum( 0 ),
			AirOutletNodeNum( 0 ),
			WaterInletNodeNum( 0 ),
			WaterOutletNodeNum( 0 ),
			WaterLoopNum( 0 ),
			WaterLoopSide( 0 ),
			WaterLoopBranchNum( 0 ),
			WaterLoopCompNum( 0 ),
			CondensateCollectMode( CondensateDiscarded ),
			CondensateTankID( 0 ),
			CondensateTankSupplyARRID( 0 ),
			CondensateVdot( 0.0 ),
			CondensateVol( 0.0 ),
			CoilPerfInpMeth( 0 ),
			FoulingFactor( 0.0 )
		{}

		// Member Constructor
		WaterCoilEquipConditions(
			std::string const & Name, // Name of the WaterCoil
			std::string const & WaterCoilTypeA, // Type of WaterCoil ie. Heating or Cooling
			std::string const & WaterCoilModelA, // Type of WaterCoil ie. Simple, Detailed, etc.
			int const WaterCoilType, // Type of WaterCoil ie. Heating or Cooling
			int const WaterCoilModel, // Type of WaterCoil ie. Simple, Detailed, etc.
			int const WaterCoilType_Num,
			std::string const & Schedule, // WaterCoil Operation Schedule
			int const SchedPtr, // Pointer to the correct schedule
			bool const RequestingAutoSize, // True if this coil has appropriate autosize fields
			Real64 const InletAirMassFlowRate, // MassFlow through the WaterCoil being Simulated [kg/s]
			Real64 const OutletAirMassFlowRate, // MassFlow throught the WaterCoil being Simulated[kg/s]
			Real64 const InletAirTemp, // Inlet Air Temperature Operating Condition [C]
			Real64 const OutletAirTemp, // Outlet Air Temperature Operating Condition [C]
			Real64 const InletAirHumRat, // Inlet Air Humidity Ratio Operating Condition
			Real64 const OutletAirHumRat, // Outlet Air Humidity Ratio Calculated Condition
			Real64 const InletAirEnthalpy, // Inlet Air enthalpy [J/kg]
			Real64 const OutletAirEnthalpy, // Outlet Air enthalpy [J/kg]
			Real64 const TotWaterCoilLoad, // Total Load on the Coil [W]
			Real64 const SenWaterCoilLoad, // Sensible Load on the Coil [W]
			Real64 const TotWaterHeatingCoilEnergy, // Total Heating Coil energy of the Coil [J]
			Real64 const TotWaterCoolingCoilEnergy, // Total Cooling Coil energy of the Coil [J]
			Real64 const SenWaterCoolingCoilEnergy, // Sensible Cooling Coil energy of the Coil [J]
			Real64 const DesWaterHeatingCoilRate, // Design Heating Coil Rate used for sizing [W]
			Real64 const TotWaterHeatingCoilRate, // Total Heating Coil Rate on the Coil [W]
			Real64 const DesWaterCoolingCoilRate, // Design Cooling Coil Rate used for sizing [W]
			Real64 const TotWaterCoolingCoilRate, // Total Cooling Coil Rate on the Coil [W]
			Real64 const SenWaterCoolingCoilRate, // Sensible Cooling Coil Rate on the Coil [W]
			Real64 const UACoil, // WaterCoil UA Value
			Real64 const LeavingRelHum, // Simple Coil Latent Model requires User input for leaving RH
			Real64 const DesiredOutletTemp,
			Real64 const DesiredOutletHumRat,
			Real64 const InletWaterTemp, // Inlet Water Temperature [C]
			Real64 const OutletWaterTemp, // Outlet Water Temperature [C]
			Real64 const InletWaterMassFlowRate, // Inlet Water Mass Flow Rate [Kg/s]
			Real64 const OutletWaterMassFlowRate, // Outlet Water Mass Flow Rate [Kg/s]
			Real64 const MaxWaterVolFlowRate, // Maximum water Volume flow rate [m3/s]
			Real64 const MaxWaterMassFlowRate, // Maximum water mass flow rate [Kg/s]
			Real64 const InletWaterEnthalpy, // Inlet Water Enthalpy
			Real64 const OutletWaterEnthalpy, // Outlet Water Enthalpy
			Real64 const TubeOutsideSurfArea, // Tube Primary Surface Area
			Real64 const TotTubeInsideArea, // Total Tube inside Surface Area
			Real64 const FinSurfArea, // Fin Surface Area
			Real64 const MinAirFlowArea,
			Real64 const CoilDepth,
			Real64 const FinDiam, // Fin Diameter or the Coil Height
			Real64 const FinThickness,
			Real64 const TubeInsideDiam, // Inner diameter of Tubes
			Real64 const TubeOutsideDiam, // Outer Diameter of the Tubes
			Real64 const TubeThermConductivity,
			Real64 const FinThermConductivity,
			Real64 const FinSpacing, // Fin Spacing or Distance
			Real64 const TubeDepthSpacing,
			int const NumOfTubeRows,
			int const NumOfTubesPerRow,
			Real64 const EffectiveFinDiam,
			Real64 const TotCoilOutsideSurfArea,
			Real64 const CoilEffectiveInsideDiam,
			Real64 const GeometryCoef1,
			Real64 const GeometryCoef2,
			FArray1< Real64 > const & DryFinEfficncyCoef,
			Real64 const SatEnthlCurveConstCoef,
			Real64 const SatEnthlCurveSlope,
			Real64 const EnthVsTempCurveAppxSlope,
			Real64 const EnthVsTempCurveConst,
			Real64 const MeanWaterTempSaved,
			Real64 const InWaterTempSaved,
			Real64 const OutWaterTempSaved,
			Real64 const SurfAreaWetSaved,
			Real64 const SurfAreaWetFraction,
			Real64 const DesInletWaterTemp, // Entering water temperature at Design(C)
			Real64 const DesAirVolFlowRate, // Entering Air Volume Flow Rate Design( m3/s)
			Real64 const DesInletAirTemp, // Entering air dry bulb temperature at Design(C)
			Real64 const DesInletAirHumRat, // Entering air humidity ratio at design conditions
			Real64 const DesTotWaterCoilLoad, // Total heat transfer rate at Design(Watt)
			Real64 const DesSenWaterCoilLoad, // Sensible heat transfer rate at Design(Watt)
			Real64 const DesAirMassFlowRate, // Design Air MassFlow through the WaterCoil [kg/Sec]
			Real64 const UACoilTotal, // Overall external dry UA (W/C)
			Real64 const UACoilInternal, // Overall internal UA(W/C)
			Real64 const UACoilExternal, // Overall external heat transfer coefficient(W/C)
			Real64 const UACoilInternalDes, // Overall design internal UA(W/C)
			Real64 const UACoilExternalDes, // Overall design external heat transfer coefficient(W/C)
			Real64 const DesOutletAirTemp, // Leaving air temperature at rating(C)
			Real64 const DesOutletAirHumRat, // Humidity ratio of air leaving at design capacity.
			Real64 const DesOutletWaterTemp, // Temp of Liquid Leaving the Coil at design Capacity
			int const HeatExchType, // Heat exchanger configuration, default to Cross Flow
			int const CoolingCoilAnalysisMode, // Mode Of analysis, Simple=1 and Detailed =2
			Real64 const UACoilInternalPerUnitArea, // Internal overall heat transfer coefficient(W/m2 C)
			Real64 const UAWetExtPerUnitArea, // External overall heat transfer coefficient(W/m2 C)
			Real64 const UADryExtPerUnitArea, // External overall heat transfer coefficient(W/m2 C)
			Real64 const SurfAreaWetFractionSaved, // Previous saved value, for numerical efficiency.
			Real64 const UACoilVariable, // WaterCoil UA value when variable (simple heating coil only)
			Real64 const RatioAirSideToWaterSideConvect, // "r" value for coil,
			Real64 const AirSideNominalConvect, // nominal rating point air side convection term (fin_effic*(hc*A))
			Real64 const LiquidSideNominalConvect, // nominal rating point water side convection term (hc*A)
			int const Control, // Const Vol =1;  Variable Vol = 2
			int const AirInletNodeNum,
			int const AirOutletNodeNum,
			int const WaterInletNodeNum,
			int const WaterOutletNodeNum,
			int const WaterLoopNum, // Plant loop index
			int const WaterLoopSide, // Plant loop side index
			int const WaterLoopBranchNum, // Plant loop branch index
			int const WaterLoopCompNum, // Plant loop Comp index
			int const CondensateCollectMode, // where does water come from
			std::string const & CondensateCollectName, // name of water source e.g. water storage tank
			int const CondensateTankID, // index "pointer" to Storage TAnk array WaterStorage
			int const CondensateTankSupplyARRID, // index pointe to supply Vdot array in WaterStorage
			Real64 const CondensateVdot, // rate of water condensation from air stream [m3/s]
			Real64 const CondensateVol, // amount of water condensed from air stream [m3]
			int const CoilPerfInpMeth, // 1 = UA and Design Water Flow Rate; 2 = Nominal Capacity
			Real64 const FoulingFactor // Coil fouling factor [m2K/W]
		) :
			Name( Name ),
			WaterCoilTypeA( WaterCoilTypeA ),
			WaterCoilModelA( WaterCoilModelA ),
			WaterCoilType( WaterCoilType ),
			WaterCoilModel( WaterCoilModel ),
			WaterCoilType_Num( WaterCoilType_Num ),
			Schedule( Schedule ),
			SchedPtr( SchedPtr ),
			RequestingAutoSize( RequestingAutoSize ),
			InletAirMassFlowRate( InletAirMassFlowRate ),
			OutletAirMassFlowRate( OutletAirMassFlowRate ),
			InletAirTemp( InletAirTemp ),
			OutletAirTemp( OutletAirTemp ),
			InletAirHumRat( InletAirHumRat ),
			OutletAirHumRat( OutletAirHumRat ),
			InletAirEnthalpy( InletAirEnthalpy ),
			OutletAirEnthalpy( OutletAirEnthalpy ),
			TotWaterCoilLoad( TotWaterCoilLoad ),
			SenWaterCoilLoad( SenWaterCoilLoad ),
			TotWaterHeatingCoilEnergy( TotWaterHeatingCoilEnergy ),
			TotWaterCoolingCoilEnergy( TotWaterCoolingCoilEnergy ),
			SenWaterCoolingCoilEnergy( SenWaterCoolingCoilEnergy ),
			DesWaterHeatingCoilRate( DesWaterHeatingCoilRate ),
			TotWaterHeatingCoilRate( TotWaterHeatingCoilRate ),
			DesWaterCoolingCoilRate( DesWaterCoolingCoilRate ),
			TotWaterCoolingCoilRate( TotWaterCoolingCoilRate ),
			SenWaterCoolingCoilRate( SenWaterCoolingCoilRate ),
			UACoil( UACoil ),
			LeavingRelHum( LeavingRelHum ),
			DesiredOutletTemp( DesiredOutletTemp ),
			DesiredOutletHumRat( DesiredOutletHumRat ),
			InletWaterTemp( InletWaterTemp ),
			OutletWaterTemp( OutletWaterTemp ),
			InletWaterMassFlowRate( InletWaterMassFlowRate ),
			OutletWaterMassFlowRate( OutletWaterMassFlowRate ),
			MaxWaterVolFlowRate( MaxWaterVolFlowRate ),
			MaxWaterMassFlowRate( MaxWaterMassFlowRate ),
			InletWaterEnthalpy( InletWaterEnthalpy ),
			OutletWaterEnthalpy( OutletWaterEnthalpy ),
			TubeOutsideSurfArea( TubeOutsideSurfArea ),
			TotTubeInsideArea( TotTubeInsideArea ),
			FinSurfArea( FinSurfArea ),
			MinAirFlowArea( MinAirFlowArea ),
			CoilDepth( CoilDepth ),
			FinDiam( FinDiam ),
			FinThickness( FinThickness ),
			TubeInsideDiam( TubeInsideDiam ),
			TubeOutsideDiam( TubeOutsideDiam ),
			TubeThermConductivity( TubeThermConductivity ),
			FinThermConductivity( FinThermConductivity ),
			FinSpacing( FinSpacing ),
			TubeDepthSpacing( TubeDepthSpacing ),
			NumOfTubeRows( NumOfTubeRows ),
			NumOfTubesPerRow( NumOfTubesPerRow ),
			EffectiveFinDiam( EffectiveFinDiam ),
			TotCoilOutsideSurfArea( TotCoilOutsideSurfArea ),
			CoilEffectiveInsideDiam( CoilEffectiveInsideDiam ),
			GeometryCoef1( GeometryCoef1 ),
			GeometryCoef2( GeometryCoef2 ),
			DryFinEfficncyCoef( 5, DryFinEfficncyCoef ),
			SatEnthlCurveConstCoef( SatEnthlCurveConstCoef ),
			SatEnthlCurveSlope( SatEnthlCurveSlope ),
			EnthVsTempCurveAppxSlope( EnthVsTempCurveAppxSlope ),
			EnthVsTempCurveConst( EnthVsTempCurveConst ),
			MeanWaterTempSaved( MeanWaterTempSaved ),
			InWaterTempSaved( InWaterTempSaved ),
			OutWaterTempSaved( OutWaterTempSaved ),
			SurfAreaWetSaved( SurfAreaWetSaved ),
			SurfAreaWetFraction( SurfAreaWetFraction ),
			DesInletWaterTemp( DesInletWaterTemp ),
			DesAirVolFlowRate( DesAirVolFlowRate ),
			DesInletAirTemp( DesInletAirTemp ),
			DesInletAirHumRat( DesInletAirHumRat ),
			DesTotWaterCoilLoad( DesTotWaterCoilLoad ),
			DesSenWaterCoilLoad( DesSenWaterCoilLoad ),
			DesAirMassFlowRate( DesAirMassFlowRate ),
			UACoilTotal( UACoilTotal ),
			UACoilInternal( UACoilInternal ),
			UACoilExternal( UACoilExternal ),
			UACoilInternalDes( UACoilInternalDes ),
			UACoilExternalDes( UACoilExternalDes ),
			DesOutletAirTemp( DesOutletAirTemp ),
			DesOutletAirHumRat( DesOutletAirHumRat ),
			DesOutletWaterTemp( DesOutletWaterTemp ),
			HeatExchType( HeatExchType ),
			CoolingCoilAnalysisMode( CoolingCoilAnalysisMode ),
			UACoilInternalPerUnitArea( UACoilInternalPerUnitArea ),
			UAWetExtPerUnitArea( UAWetExtPerUnitArea ),
			UADryExtPerUnitArea( UADryExtPerUnitArea ),
			SurfAreaWetFractionSaved( SurfAreaWetFractionSaved ),
			UACoilVariable( UACoilVariable ),
			RatioAirSideToWaterSideConvect( RatioAirSideToWaterSideConvect ),
			AirSideNominalConvect( AirSideNominalConvect ),
			LiquidSideNominalConvect( LiquidSideNominalConvect ),
			Control( Control ),
			AirInletNodeNum( AirInletNodeNum ),
			AirOutletNodeNum( AirOutletNodeNum ),
			WaterInletNodeNum( WaterInletNodeNum ),
			WaterOutletNodeNum( WaterOutletNodeNum ),
			WaterLoopNum( WaterLoopNum ),
			WaterLoopSide( WaterLoopSide ),
			WaterLoopBranchNum( WaterLoopBranchNum ),
			WaterLoopCompNum( WaterLoopCompNum ),
			CondensateCollectMode( CondensateCollectMode ),
			CondensateCollectName( CondensateCollectName ),
			CondensateTankID( CondensateTankID ),
			CondensateTankSupplyARRID( CondensateTankSupplyARRID ),
			CondensateVdot( CondensateVdot ),
			CondensateVol( CondensateVol ),
			CoilPerfInpMeth( CoilPerfInpMeth ),
			FoulingFactor( FoulingFactor )
		{}

	};
	struct WaterCoilNumericFieldData
	{
		// Members
		FArray1D_string FieldNames;

		// Default Constructor
		WaterCoilNumericFieldData()
		{}

		// Member Constructor
		WaterCoilNumericFieldData(
			FArray1_string const & FieldNames // Name of the WaterCoil numeric field descriptions
		) :
			FieldNames( FieldNames )
		{}
	};

	// Object Data
	extern FArray1D< WaterCoilEquipConditions > WaterCoil;
	extern FArray1D< WaterCoilNumericFieldData > WaterCoilNumericFields;

	// Functions

	void
	SimulateWaterCoilComponents(
		std::string const & CompName,
		bool const FirstHVACIteration,
		int & CompIndex,
		Optional< Real64 > QActual = _,
		Optional_int_const FanOpMode = _,
		Optional< Real64 const > PartLoadRatio = _
	);

	// Get Input Section of the Module
	//******************************************************************************

	void
	GetWaterCoilInput();

	// End of Get Input subroutines for the HB Module
	//******************************************************************************

	// Beginning Initialization Section of the Module
	//******************************************************************************

	void
	InitWaterCoil(
		int const CoilNum,
		bool const FirstHVACIteration // unused1208
	);

	void
	SizeWaterCoil( int const CoilNum );

	// End Initialization Section of the Module
	//******************************************************************************

	// Begin Algorithm Section of the Module
	//******************************************************************************

	void
	CalcSimpleHeatingCoil(
		int const CoilNum, // index to heating coil
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio, // part-load ratio of heating coil
		int const CalcMode // 1 = design calc; 2 = simulation calculation
	);

	void
	CalcDetailFlatFinCoolingCoil(
		int const CoilNum,
		int const CalcMode,
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio // part-load ratio of heating coil
	);

	void
	CoolingCoil(
		int const CoilNum,
		bool const FirstHVACIteration,
		int const CalcMode,
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio // part-load ratio of heating coil
	);

	// End Algorithm Section of the Module

	// Coil Completely Dry Subroutine for Cooling Coil

	void
	CoilCompletelyDry(
		int const CoilNum,
		Real64 const WaterTempIn, // Entering water temperature
		Real64 const AirTempIn, // Entering air dry bulb temperature
		Real64 const CoilUA, // Overall heat transfer coefficient
		Real64 & OutletWaterTemp, // Leaving water temperature
		Real64 & OutletAirTemp, // Leaving air dry bulb temperature
		Real64 & OutletAirHumRat, // Leaving air humidity ratio
		Real64 & Q, // Heat transfer rate
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio // part-load ratio of heating coil
	);

	// Coil Completely Wet Subroutine for Cooling Coil

	void
	CoilCompletelyWet(
		int const CoilNum, // Number of Coil
		Real64 const WaterTempIn, // Water temperature IN to this function (C)
		Real64 const AirTempIn, // Air dry bulb temperature IN to this function(C)
		Real64 const AirHumRat, // Air Humidity Ratio IN to this funcation (C)
		Real64 const UAInternalTotal, // Internal overall heat transfer coefficient(W/m2 C)
		Real64 const UAExternalTotal, // External overall heat transfer coefficient(W/m2 C)
		Real64 & OutletWaterTemp, // Leaving water temperature (C)
		Real64 & OutletAirTemp, // Leaving air dry bulb temperature(C)
		Real64 & OutletAirHumRat, // Leaving air humidity ratio
		Real64 & TotWaterCoilLoad, // Total heat transfer rate(W)
		Real64 & SenWaterCoilLoad, // Sensible heat transfer rate(W)
		Real64 & SurfAreaWetFraction, // Fraction of surface area wet
		Real64 & AirInletCoilSurfTemp, // Surface temperature at air entrance(C)
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio // part-load ratio of heating coil
	);

	// Coil Part Wet Part Dry Subroutine for Cooling Coil

	void
	CoilPartWetPartDry(
		int const CoilNum, // Number of Coil
		bool const FirstHVACIteration, // Saving Old values
		Real64 const InletWaterTemp, // Entering liquid temperature(C)
		Real64 const InletAirTemp, // Entering air dry bulb temperature(C)
		Real64 const AirDewPointTemp, // Entering air dew point(C)
		Real64 & OutletWaterTemp, // Leaving liquid temperature(C)
		Real64 & OutletAirTemp, // Leaving air dry bulb temperature(C)
		Real64 & OutletAirHumRat, // Leaving air humidity ratio
		Real64 & TotWaterCoilLoad, // Total heat transfer rate (W)
		Real64 & SenWaterCoilLoad, // Sensible heat transfer rate (W)
		Real64 & SurfAreaWetFraction, // Fraction of surface area wet
		int const FanOpMode, // fan operating mode
		Real64 const PartLoadRatio // part-load ratio of heating coil
	);

	// Calculating coil UA for Cooling Coil

	Real64
	CalcCoilUAbyEffectNTU(
		int const CoilNum,
		Real64 const CapacityStream1, // Capacity rate of stream1.(W/C)
		Real64 const EnergyInStreamOne, // Inlet state of stream1.(C)
		Real64 const CapacityStream2, // Capacity rate of stream2.(W/C)
		Real64 const EnergyInStreamTwo, // Inlet state of stream2.(C)
		Real64 const DesTotalHeatTransfer // Heat transfer rate(W)
	);

	// Calculating coil outlet stream conditions and coil UA for Cooling Coil

	void
	CoilOutletStreamCondition(
		int const CoilNum,
		Real64 const CapacityStream1, // Capacity rate of stream1(W/C)
		Real64 const EnergyInStreamOne, // Inlet state of stream1 (C)
		Real64 const CapacityStream2, // Capacity rate of stream2 (W/C)
		Real64 const EnergyInStreamTwo, // Inlet state of stream2 (C)
		Real64 const CoilUA, // Heat transfer rateW)
		Real64 & EnergyOutStreamOne, // Outlet state of stream1 (C)
		Real64 & EnergyOutStreamTwo // Outlet state of stream2 (C)
	);

	// Subroutine for caculating outlet condition if coil is wet , for Cooling Coil

	void
	WetCoilOutletCondition(
		int const CoilNum,
		Real64 const AirTempIn, // Entering air dry bulb temperature(C)
		Real64 const EnthAirInlet, // Entering air enthalpy(J/kg)
		Real64 const EnthAirOutlet, // Leaving air enthalpy(J/kg)
		Real64 const UACoilExternal, // Heat transfer coefficient for external surface (W/C)
		Real64 & OutletAirTemp, // Leaving air dry bulb temperature(C)
		Real64 & OutletAirHumRat, // Leaving air humidity ratio
		Real64 & SenWaterCoilLoad // Sensible heat transfer rate(W)
	);

	// Beginning of Update subroutines for the WaterCoil Module
	// *****************************************************************************

	void
	UpdateWaterCoil( int const CoilNum );

	//        End of Update subroutines for the WaterCoil Module
	// *****************************************************************************

	// Beginning of Reporting subroutines for the WaterCoil Module
	// *****************************************************************************

	void
	ReportWaterCoil( int const CoilNum );

	//        End of Reporting subroutines for the WaterCoil Module
	// *****************************************************************************

	// Beginning of Coil Utility subroutines for the Detailed Model
	// *****************************************************************************

	void
	CalcDryFinEffCoef(
		Real64 const OutTubeEffFinDiamRatio,
		FArray1< Real64 > & PolynomCoef
	);

	void
	CalcIBesselFunc(
		Real64 const BessFuncArg,
		int const BessFuncOrd,
		Real64 & IBessFunc,
		int & ErrorCode
	);

	void
	CalcKBesselFunc(
		Real64 const BessFuncArg,
		int const BessFuncOrd,
		Real64 & KBessFunc,
		int & ErrorCode
	);

	void
	CalcPolynomCoef(
		FArray2< Real64 > const & OrderedPair,
		FArray1< Real64 > & PolynomCoef
	);

	Real64
	SimpleHeatingCoilUAResidual(
		Real64 const UA, // UA of coil
		Optional< FArray1S< Real64 > const > Par = _ // par(1) = design coil load [W]
	);

	Real64
	SimpleCoolingCoilUAResidual(
		Real64 const UA, // UA of coil
		Optional< FArray1S< Real64 > const > Par = _ // par(1) = design coil load [W]
	);

	// Iterate Routine for Cooling Coil

	void
	CoilAreaFracIter(
		Real64 & NewSurfAreaWetFrac, // Out Value of variable
		Real64 const SurfAreaFracCurrent, // Driver Value
		Real64 const ErrorCurrent, // Objective Function
		Real64 & SurfAreaFracPrevious, // First Previous value of Surf Area Fraction
		Real64 & ErrorPrevious, // First Previous value of error
		Real64 & SurfAreaFracLast, // Second Previous value of Surf Area Fraction
		Real64 & ErrorLast, // Second Previous value of error
		int const IterNum, // Number of Iterations
		int & icvg // Iteration convergence flag
	);

	void
	CheckWaterCoilSchedule(
		std::string const & CompType, // unused1208
		std::string const & CompName,
		Real64 & Value,
		int & CompIndex
	);

	Real64
	GetCoilMaxWaterFlowRate(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	int
	GetCoilInletNode(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	int
	GetCoilOutletNode(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	int
	GetCoilWaterInletNode(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	int
	GetCoilWaterOutletNode(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	void
	SetCoilDesFlow(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		Real64 const CoilDesFlow, // coil volumetric air flow rate [m3/s]
		bool & ErrorsFound // set to true if problem
	);

	void
	CheckActuatorNode(
		int const ActuatorNodeNum, // input actuator node number
		int & iNodeType, // Cooling or Heating or 0
		bool & NodeNotFound // true if matching water inlet node not found
	);

	void
	CheckForSensorAndSetPointNode(
		int const SensorNodeNum, // controller sensor node number
		int const ControlledVar, // controlled variable type
		bool & NodeNotFound // true if matching air outlet node not found
	);

	Real64
	TdbFnHRhPb(
		Real64 const H, // specific enthalpy {J/kg}
		Real64 const RH, // relative humidity value (0.0-1.0)
		Real64 const PB // barometric pressure {Pascals}
	);

	Real64
	EnthalpyResidual(
		Real64 const Tprov, // test value of Tdb [C]
		Optional< FArray1S< Real64 > const > Par = _ // Par(1) = desired enthaply H [J/kg]
	);

	Real64
	EstimateHEXSurfaceArea( int const CoilNum ); // coil number, [-]

	int
	GetWaterCoilIndex(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	Real64
	GetWaterCoilCapacity(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	void
	UpdateWaterToAirCoilPlantConnection(
		int const CoilTypeNum,
		std::string const & CoilName,
		int const EquipFlowCtrl, // Flow control mode for the equipment
		int const LoopNum, // Plant loop index for where called from
		int const LoopSide, // Plant loop side index for where called from
		int & CompIndex, // Chiller number pointer
		bool const FirstHVACIteration,
		bool & InitLoopEquip // If not zero, calculate the max load for operating conditions
	);

	int
	GetWaterCoilAvailScheduleIndex(
		std::string const & CoilType, // must match coil types in this module
		std::string const & CoilName, // must match coil names for the coil type
		bool & ErrorsFound // set to true if problem
	);

	// End of Coil Utility subroutines
	// *****************************************************************************

	//     NOTICE

	//     Copyright � 1996-2014 The Board of Trustees of the University of Illinois
	//     and The Regents of the University of California through Ernest Orlando Lawrence
	//     Berkeley National Laboratory.  All rights reserved.

	//     Portions of the EnergyPlus software package have been developed and copyrighted
	//     by other individuals, companies and institutions.  These portions have been
	//     incorporated into the EnergyPlus software package under license.   For a complete
	//     list of contributors, see "Notice" located in EnergyPlus.f90.

	//     NOTICE: The U.S. Government is granted for itself and others acting on its
	//     behalf a paid-up, nonexclusive, irrevocable, worldwide license in this data to
	//     reproduce, prepare derivative works, and perform publicly and display publicly.
	//     Beginning five (5) years after permission to assert copyright is granted,
	//     subject to two possible five year renewals, the U.S. Government is granted for
	//     itself and others acting on its behalf a paid-up, non-exclusive, irrevocable
	//     worldwide license in this data to reproduce, prepare derivative works,
	//     distribute copies to the public, perform publicly and display publicly, and to
	//     permit others to do so.

	//     TRADEMARKS: EnergyPlus is a trademark of the US Department of Energy.

} // WaterCoils

} // EnergyPlus

#endif
