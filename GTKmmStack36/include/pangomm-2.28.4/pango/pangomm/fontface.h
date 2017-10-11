// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _PANGOMM_FONTFACE_H
#define _PANGOMM_FONTFACE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: fontface.hg,v 1.3 2004/03/03 01:07:40 murrayc Exp $ */

/* fontface.h
 * 
 * Copyright 2001      The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <pangomm/fontdescription.h>
#include <glibmm/object.h>
#include <glibmm/arrayhandle.h>
#include <pango/pango-font.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _PangoFontFace PangoFontFace;
typedef struct _PangoFontFaceClass PangoFontFaceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{ class FontFace_Class; } // namespace Pango
namespace Pango
{

/** A Pango::FontFace is used to represent a group of fonts with the same family, slant, weight, width, but varying sizes.
 */

class FontFace : public Glib::Object
{
   
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef FontFace CppObjectType;
  typedef FontFace_Class CppClassType;
  typedef PangoFontFace BaseObjectType;
  typedef PangoFontFaceClass BaseClassType;

private:  friend class FontFace_Class;
  static CppClassType fontface_class_;

private:
  // noncopyable
  FontFace(const FontFace&);
  FontFace& operator=(const FontFace&);

protected:
  explicit FontFace(const Glib::ConstructParams& construct_params);
  explicit FontFace(PangoFontFace* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~FontFace();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  PangoFontFace*       gobj()       { return reinterpret_cast<PangoFontFace*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const PangoFontFace* gobj() const { return reinterpret_cast<PangoFontFace*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  PangoFontFace* gobj_copy();

private:


public:
  
  /** Returns the family, style, variant, weight and stretch of
   * a Pango::FontFace. The size field of the resulting font description
   * will be unset.
   * @return A  Pango::FontDescription 
   * holding the description of the face.
   */
  FontDescription describe() const;
  
  /** Gets a name representing the style of this face among the
   * different faces in the Pango::FontFamily for the face. This
   * name is unique among all faces in the family and is suitable
   * for displaying to users.
   * @return The face name for the face. This string is
   * owned by the face object and must not be modified or freed.
   */
  Glib::ustring get_name() const;

  /** List the available sizes for a font. This is only applicable to bitmap fonts. 
   * For scalable fonts this returns an empty array. 
   * The sizes returned are in Pango units and are sorted in ascending order.
   */
  Glib::ArrayHandle<int> list_sizes() const;
  

  /** Returns whether a Pango::FontFace is synthesized by the underlying
   * font rendering engine from another face, perhaps by shearing, emboldening,
   * or lightening it.
   * 
   * @newin{1,18}
   * @return Whether @a face is synthesized.
   */
  bool is_synthesized() const;
  
protected:
  //We can't wrap the virtual functions because PangoFontFace has a hidden class.
  //We probably don't need to subclass this anyway.
  //_WRAP_VFUNC(const char* get_name() const, "get_face_name")
  //_WRAP_VFUNC(PangoFontDescription* describe(), "describe")


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::FontFace
   */
  Glib::RefPtr<Pango::FontFace> wrap(PangoFontFace* object, bool take_copy = false);
}


#endif /* _PANGOMM_FONTFACE_H */

