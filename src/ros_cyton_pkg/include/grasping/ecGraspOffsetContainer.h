#ifndef ecGraspOffsetContainer_H_
#define ecGraspOffsetContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspOffsetContainer.h
/// @class EcGraspOffsetContainer
/// @brief Container for grasp offsets
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcGraspOffset;

/// Container for grasp offsets
class EC_ACTIN_GRASPING_DECL EcGraspOffsetContainer :
   public EcXmlVariableElementType<EcGraspOffset>
{
public:
   /// default constructor
   EcGraspOffsetContainer
      (
      );

   /// destructor
   virtual ~EcGraspOffsetContainer
      (
      );

   /// copy constructor
   EcGraspOffsetContainer
      (
      const EcGraspOffsetContainer& orig
      );

   /// assignment operator
   EcGraspOffsetContainer& operator=
      (
      const EcGraspOffsetContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspOffsetContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// null object
   static EcGraspOffsetContainer nullObject
      (
      );
};

/// an XML readable/writable vector of EcGraspOffsetContainer objects
typedef EcXmlVectorType<EcGraspOffsetContainer> EcGraspOffsetContainerVector;

#endif // ecGraspOffsetContainer_H_
