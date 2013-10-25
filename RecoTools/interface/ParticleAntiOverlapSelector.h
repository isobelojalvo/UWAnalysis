#ifndef TauAnalysis_CandidateTools_ParticleAntiOverlapSelector_h
#define TauAnalysis_CandidateTools_ParticleAntiOverlapSelector_h

/** \class ParticleAntiOverlapSelector
 *
 * Remove particles overlapping with other particles,
 * in order to avoud double-counting
 * 
 * \author Alfredo Gurrola, Texas A&M;
 *  modified by Konstantinos A. Petridis,
 *              Christian Veelken
 *
 * \version $Revision: 1.1 $
 *
 * $Id: ParticleAntiOverlapSelector.h,v 1.1 2012/06/13 19:51:29 efriis Exp $
 *
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/Candidate/interface/CandidateFwd.h" 
#include "DataFormats/Candidate/interface/Candidate.h" 

#include "DataFormats/Math/interface/deltaR.h"

#include <vector>

template <class T>
class ParticleAntiOverlapSelector
{
 public:
  typedef std::vector<T> collection;

  explicit ParticleAntiOverlapSelector(const edm::ParameterSet& cfg)
  {
    srcNotToBeFiltered_ = cfg.getParameter<vInputTag>("srcNotToBeFiltered");
    dRmin_ = cfg.getParameter<double>("dRmin");
    invert_ = ( cfg.exists("invert") ) ?
      cfg.getParameter<bool>("invert") : false;
  }

  typename std::vector<const T*>::const_iterator begin() const { return selected_.begin(); }
  typename std::vector<const T*>::const_iterator end() const { return selected_.end(); }

  void select(const edm::Handle<collection>& particlesToBeFiltered, const edm::Event& evt, const edm::EventSetup& es)
  {
    selected_.clear();

    std::vector<bool> isOverlap(particlesToBeFiltered->size());
    
    for ( vInputTag::const_iterator it = srcNotToBeFiltered_.begin();
	  it != srcNotToBeFiltered_.end(); ++it ) {
      
      edm::Handle<reco::CandidateView> particlesNotToBeFiltered;
      evt.getByLabel(*it, particlesNotToBeFiltered);
      
      for ( reco::CandidateView::const_iterator particleNotToBeFiltered = particlesNotToBeFiltered->begin();
	    particleNotToBeFiltered != particlesNotToBeFiltered->end(); ++particleNotToBeFiltered ) {
	
	int particleToBeFilteredIndex = 0;
	for ( typename collection::const_iterator particleToBeFiltered = particlesToBeFiltered->begin();
	      particleToBeFiltered != particlesToBeFiltered->end(); ++particleToBeFiltered, ++particleToBeFilteredIndex ) {
	  
	  double dR = reco::deltaR(particleToBeFiltered->p4(), particleNotToBeFiltered->p4());
	  
	  if ( dR < dRmin_ ) isOverlap[particleToBeFilteredIndex] = true;
	}
      }
    }
    
    int particleToBeFilteredIndex = 0;
    for ( typename collection::const_iterator particleToBeFiltered = particlesToBeFiltered->begin();
	  particleToBeFiltered != particlesToBeFiltered->end(); ++particleToBeFiltered, ++particleToBeFilteredIndex ) {
      if ( !invert_ ) {
	if ( !isOverlap[particleToBeFilteredIndex] ) selected_.push_back(&(*particleToBeFiltered)); 
      } else {
	if ( isOverlap[particleToBeFilteredIndex] ) selected_.push_back(&(*particleToBeFiltered)); 
      }
    }
  }

  size_t size() const { return selected_.size(); }

 private:
  std::vector<const T*> selected_;

  typedef std::vector<edm::InputTag> vInputTag;
  vInputTag srcNotToBeFiltered_;

  //when invert is TRUE the selector looks for overlapping objects
  bool invert_;

  double dRmin_;
};

#endif
