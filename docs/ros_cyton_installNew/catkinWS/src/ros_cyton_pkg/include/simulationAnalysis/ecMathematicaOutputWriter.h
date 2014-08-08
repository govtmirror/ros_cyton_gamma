#ifndef ecMathematicaOutputWriter_H_
#define ecMathematicaOutputWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecMathematicaOutputWriter.h
/// @class EcMathematicaOutputWriter
/// @brief A class for writing simulation outputs to files in Mathematica
///        format.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseOutputWriter.h"

/** A class for writing simulation outputs to files in Mathematica format.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcMathematicaOutputWriter : public EcBaseOutputWriter
{
public:
   /// default constructor
   EcMathematicaOutputWriter
      (
      );

   /// destructor
   virtual ~EcMathematicaOutputWriter
      (
      );

   /// copy constructor
   EcMathematicaOutputWriter
      (
      const EcMathematicaOutputWriter& orig
      );

   /// assignment operator
   EcMathematicaOutputWriter& operator=
      (
      const EcMathematicaOutputWriter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMathematicaOutputWriter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// return the descriptor of the file format.
   virtual const EcString& formatDescriptor
      (
      ) const;

   /// return the file extension.
   virtual const EcString& fileExtension
      (
      ) const;

   /// open file
   virtual void openFile
      (
      const EcString& fileName,
      std::ofstream& stream
      );

   /// initialize the writer if necessary
   virtual void initialize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      );

   /// finalize the writer if necessary
   virtual void finalize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      );

   /// write the opening of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentOpening
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const;

   /// write a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeDataComponent
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const;

   /// write the closing of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentClosing
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcMathematicaOutputWriter nullObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// a vector of strings obtained from a data component to be written to files
   mutable EcStringVector    m_vDataComponentStrings;

   /// a string containing the format descriptor "Mathematica"
   static const EcString      m_TheFormatDescriptor;

   /// a string containing the file extension for Mathematica format (.nb)
   static const EcString      m_TheFileExtension;
};

#endif // ecMathematicaOutputWriter_H_
