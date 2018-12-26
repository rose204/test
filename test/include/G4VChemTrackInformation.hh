#ifndef INCLUDE_G4VChemTrackInformation_HH_
#define INCLUDE_G4VChemTrackInformation_HH_

#include <G4VUserTrackInformation.hh>

class G4Track;
class G4TrackingInformation;

class G4VChemTrackInformation: public G4VUserTrackInformation {
public:
	G4VChemTrackInformation();
	G4VChemTrackInformation(G4Track*);
	virtual ~G4VChemTrackInformation();



	  virtual void Print() const
	  {
	    ;
	  }
	  virtual const G4String& GetName() const = 0;

	  ///
	  // You should not worried of implementing diff, equal
	  // and GetType.
	  // When using ITDef(MyClass) this will be done.
	  // However, you need to implement in the concrete class
	  // even fake operators for < and ==
	  // They will be used by diff and equal.
	  ///
	  virtual G4bool diff(const G4VChemTrackInformation& right) const = 0;
	  virtual G4bool equal(const G4VChemTrackInformation& right) const = 0;
	  G4bool operator<(const G4VChemTrackInformation& right) const;
	  G4bool operator==(const G4VChemTrackInformation& right) const;
	  G4bool operator!=(const G4VChemTrackInformation& right) const;

	  void SetTrack(G4Track*);
	  inline G4Track* GetTrack();
	  inline const G4Track* GetTrack() const;

	  void RecordCurrentPositionNTime();
	  const G4ThreeVector& GetPosition() const;
	  double operator[](int i) const;
	  const G4ThreeVector& GetPreStepPosition() const;
	  G4double GetPreStepLocalTime() const;
	  G4double GetPreStepGlobalTime() const;

	  inline void SetPrevious(G4VChemTrackInformation*);
	  inline void SetNext(G4VChemTrackInformation*);
	  inline G4VChemTrackInformation* GetPrevious();
	  inline G4VChemTrackInformation* GetNext();
	  inline const G4VChemTrackInformation* GetPrevious() const;
	  inline const G4VChemTrackInformation* GetNext() const;
//	  inline void SetITBox(G4ITBox*);
//	  inline const G4ITBox* GetITBox() const;
//	  void TakeOutBox();

//	  inline void SetNode(G4KDNode_Base*);
//	  inline G4KDNode_Base* GetNode() const;

	  inline void SetParentID(int, int);
	  inline void GetParentID(int&, int&);

	  inline G4TrackingInformation* GetTrackingInfo()
	  {
	    return fpTrackingInformation;
	  }

//	  inline G4TrackListNode* GetListNode()
//	  {
//	    return fpTrackNode;
//	  }
//	  inline void SetListNode(G4TrackListNode* node)
//	  {
//	    fpTrackNode = node;
//	  }
//
//	  virtual const G4ITType GetITType() const = 0;
//
//	  virtual G4ITType GetITSubType() const
//	  {
//	    return 0;
//	  }

	protected:
	  G4VChemTrackInformation(const G4VChemTrackInformation&);
	  G4VChemTrackInformation& operator=(const G4VChemTrackInformation&);
	  G4Track* fpTrack;

	private:
	  G4VChemTrackInformation* fpPreviousIT;
	  G4VChemTrackInformation* fpNextIT;

	  int fParentID_A;
	  int fParentID_B;

	  G4TrackingInformation* fpTrackingInformation;
//	  G4TrackListNode* fpTrackNode;

};

#endif /* INCLUDE_G4VChemTrackInformation_HH_ */
