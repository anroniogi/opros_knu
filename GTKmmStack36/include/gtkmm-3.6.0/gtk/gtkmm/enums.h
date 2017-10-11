// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_ENUMS_H
#define _GTKMM_ENUMS_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <glibmm/value.h>
#include <gtk/gtk.h>


namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%AccelFlags operator|(AccelFlags, AccelFlags)</tt><br>
 * <tt>%AccelFlags operator&(AccelFlags, AccelFlags)</tt><br>
 * <tt>%AccelFlags operator^(AccelFlags, AccelFlags)</tt><br>
 * <tt>%AccelFlags operator~(AccelFlags)</tt><br>
 * <tt>%AccelFlags& operator|=(AccelFlags&, AccelFlags)</tt><br>
 * <tt>%AccelFlags& operator&=(AccelFlags&, AccelFlags)</tt><br>
 * <tt>%AccelFlags& operator^=(AccelFlags&, AccelFlags)</tt><br>
 */
enum AccelFlags
{
  ACCEL_VISIBLE = 1 << 0,
  ACCEL_LOCKED = 1 << 1,
  ACCEL_MASK = 0x07
};

/** @ingroup gtkmmEnums */
inline AccelFlags operator|(AccelFlags lhs, AccelFlags rhs)
  { return static_cast<AccelFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AccelFlags operator&(AccelFlags lhs, AccelFlags rhs)
  { return static_cast<AccelFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AccelFlags operator^(AccelFlags lhs, AccelFlags rhs)
  { return static_cast<AccelFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AccelFlags operator~(AccelFlags flags)
  { return static_cast<AccelFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline AccelFlags& operator|=(AccelFlags& lhs, AccelFlags rhs)
  { return (lhs = static_cast<AccelFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline AccelFlags& operator&=(AccelFlags& lhs, AccelFlags rhs)
  { return (lhs = static_cast<AccelFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline AccelFlags& operator^=(AccelFlags& lhs, AccelFlags rhs)
  { return (lhs = static_cast<AccelFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::AccelFlags> : public Glib::Value_Flags<Gtk::AccelFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/**
 * @ingroup gtkmmEnums
 */
enum Align
{
  ALIGN_FILL,
  ALIGN_START,
  ALIGN_END,
  ALIGN_CENTER
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::Align> : public Glib::Value_Enum<Gtk::Align>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** Used to indicate the direction in which a Gtk::Arrow should point.
 * @ingroup gtkmmEnums
 */
enum ArrowType
{
  ARROW_UP,
  ARROW_DOWN,
  ARROW_LEFT,
  ARROW_RIGHT,
  ARROW_NONE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ArrowType> : public Glib::Value_Enum<Gtk::ArrowType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


// TODO: There must be a better way to document the enum values.
//       Extract them from the GTK+ docs as well?

/*! @var ArrowType ARROW_UP
 * Represents an upward pointing arrow.
 */
/*! @var ArrowType ARROW_DOWN
 * Represents a downward pointing arrow.
 */
/*! @var ArrowType ARROW_LEFT
 * Represents a left pointing arrow.
 */
/*! @var ArrowType ARROW_RIGHT
 * Represents a right pointing arrow.
 */

/** Denotes the expansion properties that a widget will have when it (or its parent) is resized.
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%AttachOptions operator|(AttachOptions, AttachOptions)</tt><br>
 * <tt>%AttachOptions operator&(AttachOptions, AttachOptions)</tt><br>
 * <tt>%AttachOptions operator^(AttachOptions, AttachOptions)</tt><br>
 * <tt>%AttachOptions operator~(AttachOptions)</tt><br>
 * <tt>%AttachOptions& operator|=(AttachOptions&, AttachOptions)</tt><br>
 * <tt>%AttachOptions& operator&=(AttachOptions&, AttachOptions)</tt><br>
 * <tt>%AttachOptions& operator^=(AttachOptions&, AttachOptions)</tt><br>
 */
enum AttachOptions
{
  EXPAND = 1 << 0,
  SHRINK = 1 << 1,
  FILL = 1 << 2
};

/** @ingroup gtkmmEnums */
inline AttachOptions operator|(AttachOptions lhs, AttachOptions rhs)
  { return static_cast<AttachOptions>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AttachOptions operator&(AttachOptions lhs, AttachOptions rhs)
  { return static_cast<AttachOptions>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AttachOptions operator^(AttachOptions lhs, AttachOptions rhs)
  { return static_cast<AttachOptions>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline AttachOptions operator~(AttachOptions flags)
  { return static_cast<AttachOptions>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline AttachOptions& operator|=(AttachOptions& lhs, AttachOptions rhs)
  { return (lhs = static_cast<AttachOptions>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline AttachOptions& operator&=(AttachOptions& lhs, AttachOptions rhs)
  { return (lhs = static_cast<AttachOptions>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline AttachOptions& operator^=(AttachOptions& lhs, AttachOptions rhs)
  { return (lhs = static_cast<AttachOptions>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::AttachOptions> : public Glib::Value_Flags<Gtk::AttachOptions>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/*! @var AttachOptions EXPAND
 * The widget should expand to take up any extra space in its container that has been allocated.
 */
/*! @var AttachOptions SHRINK
 * The widget should shrink as and when possible.
 */
/** @var AttachOptions FILL
 * The widget should fill the space allocated to it.
 * @ingroup gtkmmEnums
 */
enum ButtonBoxStyle
{
  BUTTONBOX_SPREAD = 1,
  BUTTONBOX_EDGE,
  BUTTONBOX_START,
  BUTTONBOX_END,
  BUTTONBOX_CENTER
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ButtonBoxStyle> : public Glib::Value_Enum<Gtk::ButtonBoxStyle>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum DeleteType
{
  DELETE_CHARS,
  DELETE_WORD_ENDS,
  DELETE_WORDS,
  DELETE_DISPLAY_LINES,
  DELETE_DISPLAY_LINE_ENDS,
  DELETE_PARAGRAPH_ENDS,
  DELETE_PARAGRAPHS,
  DELETE_WHITESPACE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::DeleteType> : public Glib::Value_Enum<Gtk::DeleteType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum DirectionType
{
  DIR_TAB_FORWARD,
  DIR_TAB_BACKWARD,
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::DirectionType> : public Glib::Value_Enum<Gtk::DirectionType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ExpanderStyle
{
  EXPANDER_COLLAPSED,
  EXPANDER_SEMI_COLLAPSED,
  EXPANDER_SEMI_EXPANDED,
  EXPANDER_EXPANDED
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ExpanderStyle> : public Glib::Value_Enum<Gtk::ExpanderStyle>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum BuiltinIconSize
{
  ICON_SIZE_INVALID,
  ICON_SIZE_MENU,
  ICON_SIZE_SMALL_TOOLBAR,
  ICON_SIZE_LARGE_TOOLBAR,
  ICON_SIZE_BUTTON,
  ICON_SIZE_DND,
  ICON_SIZE_DIALOG
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::BuiltinIconSize> : public Glib::Value_Enum<Gtk::BuiltinIconSize>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum TextDirection
{
  TEXT_DIR_NONE,
  TEXT_DIR_LTR,
  TEXT_DIR_RTL
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::TextDirection> : public Glib::Value_Enum<Gtk::TextDirection>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum Justification
{
  JUSTIFY_LEFT,
  JUSTIFY_RIGHT,
  JUSTIFY_CENTER,
  JUSTIFY_FILL
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::Justification> : public Glib::Value_Enum<Gtk::Justification>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum MenuDirectionType
{
  MENU_DIR_PARENT,
  MENU_DIR_CHILD,
  MENU_DIR_NEXT,
  MENU_DIR_PREV
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::MenuDirectionType> : public Glib::Value_Enum<Gtk::MenuDirectionType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum MessageType
{
  MESSAGE_INFO,
  MESSAGE_WARNING,
  MESSAGE_QUESTION,
  MESSAGE_ERROR,
  MESSAGE_OTHER
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::MessageType> : public Glib::Value_Enum<Gtk::MessageType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum MovementStep
{
  MOVEMENT_LOGICAL_POSITIONS,
  MOVEMENT_VISUAL_POSITIONS,
  MOVEMENT_WORDS,
  MOVEMENT_DISPLAY_LINES,
  MOVEMENT_DISPLAY_LINE_ENDS,
  MOVEMENT_PARAGRAPHS,
  MOVEMENT_PARAGRAPH_ENDS,
  MOVEMENT_PAGES,
  MOVEMENT_BUFFER_ENDS,
  MOVEMENT_HORIZONTAL_PAGES
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::MovementStep> : public Glib::Value_Enum<Gtk::MovementStep>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum Orientation
{
  ORIENTATION_HORIZONTAL,
  ORIENTATION_VERTICAL
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::Orientation> : public Glib::Value_Enum<Gtk::Orientation>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum CornerType
{
  CORNER_TOP_LEFT,
  CORNER_BOTTOM_LEFT,
  CORNER_TOP_RIGHT,
  CORNER_BOTTOM_RIGHT
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::CornerType> : public Glib::Value_Enum<Gtk::CornerType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PackType
{
  PACK_START,
  PACK_END
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PackType> : public Glib::Value_Enum<Gtk::PackType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PathPriorityType
{
  PATH_PRIO_LOWEST = 0,
  PATH_PRIO_GTK = 4,
  PATH_PRIO_APPLICATION = 8,
  PATH_PRIO_THEME = 10,
  PATH_PRIO_RC = 12,
  PATH_PRIO_HIGHEST = 15
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PathPriorityType> : public Glib::Value_Enum<Gtk::PathPriorityType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PathType
{
  PATH_WIDGET,
  PATH_WIDGET_CLASS,
  PATH_CLASS
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PathType> : public Glib::Value_Enum<Gtk::PathType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PolicyType
{
  POLICY_ALWAYS,
  POLICY_AUTOMATIC,
  POLICY_NEVER
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PolicyType> : public Glib::Value_Enum<Gtk::PolicyType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PositionType
{
  POS_LEFT,
  POS_RIGHT,
  POS_TOP,
  POS_BOTTOM
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PositionType> : public Glib::Value_Enum<Gtk::PositionType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ReliefStyle
{
  RELIEF_NORMAL,
  RELIEF_HALF,
  RELIEF_NONE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ReliefStyle> : public Glib::Value_Enum<Gtk::ReliefStyle>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ResizeMode
{
  RESIZE_PARENT,
  RESIZE_QUEUE,
  RESIZE_IMMEDIATE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ResizeMode> : public Glib::Value_Enum<Gtk::ResizeMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ScrollType
{
  SCROLL_NONE,
  SCROLL_JUMP,
  SCROLL_STEP_BACKWARD,
  SCROLL_STEP_FORWARD,
  SCROLL_PAGE_BACKWARD,
  SCROLL_PAGE_FORWARD,
  SCROLL_STEP_UP,
  SCROLL_STEP_DOWN,
  SCROLL_PAGE_UP,
  SCROLL_PAGE_DOWN,
  SCROLL_STEP_LEFT,
  SCROLL_STEP_RIGHT,
  SCROLL_PAGE_LEFT,
  SCROLL_PAGE_RIGHT,
  SCROLL_START,
  SCROLL_END
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ScrollType> : public Glib::Value_Enum<Gtk::ScrollType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum SelectionMode
{
  SELECTION_NONE,
  SELECTION_SINGLE,
  SELECTION_BROWSE,
  SELECTION_MULTIPLE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::SelectionMode> : public Glib::Value_Enum<Gtk::SelectionMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ShadowType
{
  SHADOW_NONE,
  SHADOW_IN,
  SHADOW_OUT,
  SHADOW_ETCHED_IN,
  SHADOW_ETCHED_OUT
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ShadowType> : public Glib::Value_Enum<Gtk::ShadowType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum StateType
{
  STATE_NORMAL,
  STATE_ACTIVE,
  STATE_PRELIGHT,
  STATE_SELECTED,
  STATE_INSENSITIVE,
  STATE_INCONSISTENT,
  STATE_FOCUSED
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::StateType> : public Glib::Value_Enum<Gtk::StateType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%TargetFlags operator|(TargetFlags, TargetFlags)</tt><br>
 * <tt>%TargetFlags operator&(TargetFlags, TargetFlags)</tt><br>
 * <tt>%TargetFlags operator^(TargetFlags, TargetFlags)</tt><br>
 * <tt>%TargetFlags operator~(TargetFlags)</tt><br>
 * <tt>%TargetFlags& operator|=(TargetFlags&, TargetFlags)</tt><br>
 * <tt>%TargetFlags& operator&=(TargetFlags&, TargetFlags)</tt><br>
 * <tt>%TargetFlags& operator^=(TargetFlags&, TargetFlags)</tt><br>
 */
enum TargetFlags
{
  TARGET_SAME_APP = 1 << 0,
  TARGET_SAME_WIDGET = 1 << 1,
  TARGET_OTHER_APP = 1 << 2,
  TARGET_OTHER_WIDGET = 1 << 3
};

/** @ingroup gtkmmEnums */
inline TargetFlags operator|(TargetFlags lhs, TargetFlags rhs)
  { return static_cast<TargetFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline TargetFlags operator&(TargetFlags lhs, TargetFlags rhs)
  { return static_cast<TargetFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline TargetFlags operator^(TargetFlags lhs, TargetFlags rhs)
  { return static_cast<TargetFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline TargetFlags operator~(TargetFlags flags)
  { return static_cast<TargetFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline TargetFlags& operator|=(TargetFlags& lhs, TargetFlags rhs)
  { return (lhs = static_cast<TargetFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline TargetFlags& operator&=(TargetFlags& lhs, TargetFlags rhs)
  { return (lhs = static_cast<TargetFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline TargetFlags& operator^=(TargetFlags& lhs, TargetFlags rhs)
  { return (lhs = static_cast<TargetFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::TargetFlags> : public Glib::Value_Flags<Gtk::TargetFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum ToolbarStyle
{
  TOOLBAR_ICONS,
  TOOLBAR_TEXT,
  TOOLBAR_BOTH,
  TOOLBAR_BOTH_HORIZ
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ToolbarStyle> : public Glib::Value_Enum<Gtk::ToolbarStyle>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum WindowPosition
{
  WIN_POS_NONE,
  WIN_POS_CENTER,
  WIN_POS_MOUSE,
  WIN_POS_CENTER_ALWAYS,
  WIN_POS_CENTER_ON_PARENT
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::WindowPosition> : public Glib::Value_Enum<Gtk::WindowPosition>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum WindowType
{
  WINDOW_TOPLEVEL,
  WINDOW_POPUP
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::WindowType> : public Glib::Value_Enum<Gtk::WindowType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum WrapMode
{
  WRAP_NONE,
  WRAP_CHAR,
  WRAP_WORD,
  WRAP_WORD_CHAR
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::WrapMode> : public Glib::Value_Enum<Gtk::WrapMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum SortType
{
  SORT_ASCENDING,
  SORT_DESCENDING
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::SortType> : public Glib::Value_Enum<Gtk::SortType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum PageOrientation
{
  PAGE_ORIENTATION_PORTRAIT,
  PAGE_ORIENTATION_LANDSCAPE,
  PAGE_ORIENTATION_REVERSE_PORTRAIT,
  PAGE_ORIENTATION_REVERSE_LANDSCAPE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PageOrientation> : public Glib::Value_Enum<Gtk::PageOrientation>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum SensitivityType
{
  SENSITIVITY_AUTO,
  SENSITIVITY_ON,
  SENSITIVITY_OFF
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::SensitivityType> : public Glib::Value_Enum<Gtk::SensitivityType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum SizeRequestMode
{
  SIZE_REQUEST_HEIGHT_FOR_WIDTH,
  SIZE_REQUEST_WIDTH_FOR_HEIGHT,
  SIZE_REQUEST_CONSTANT_SIZE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::SizeRequestMode> : public Glib::Value_Enum<Gtk::SizeRequestMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%RegionFlags operator|(RegionFlags, RegionFlags)</tt><br>
 * <tt>%RegionFlags operator&(RegionFlags, RegionFlags)</tt><br>
 * <tt>%RegionFlags operator^(RegionFlags, RegionFlags)</tt><br>
 * <tt>%RegionFlags operator~(RegionFlags)</tt><br>
 * <tt>%RegionFlags& operator|=(RegionFlags&, RegionFlags)</tt><br>
 * <tt>%RegionFlags& operator&=(RegionFlags&, RegionFlags)</tt><br>
 * <tt>%RegionFlags& operator^=(RegionFlags&, RegionFlags)</tt><br>
 */
enum RegionFlags
{
  REGION_EVEN = 1 << 0,
  REGION_ODD = 1 << 1,
  REGION_FIRST = 1 << 2,
  REGION_LAST = 1 << 3,
  REGION_ONLY = 1 << 4,
  REGION_SORTED = 1 << 5
};

/** @ingroup gtkmmEnums */
inline RegionFlags operator|(RegionFlags lhs, RegionFlags rhs)
  { return static_cast<RegionFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline RegionFlags operator&(RegionFlags lhs, RegionFlags rhs)
  { return static_cast<RegionFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline RegionFlags operator^(RegionFlags lhs, RegionFlags rhs)
  { return static_cast<RegionFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline RegionFlags operator~(RegionFlags flags)
  { return static_cast<RegionFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline RegionFlags& operator|=(RegionFlags& lhs, RegionFlags rhs)
  { return (lhs = static_cast<RegionFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline RegionFlags& operator&=(RegionFlags& lhs, RegionFlags rhs)
  { return (lhs = static_cast<RegionFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline RegionFlags& operator^=(RegionFlags& lhs, RegionFlags rhs)
  { return (lhs = static_cast<RegionFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::RegionFlags> : public Glib::Value_Flags<Gtk::RegionFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%JunctionSides operator|(JunctionSides, JunctionSides)</tt><br>
 * <tt>%JunctionSides operator&(JunctionSides, JunctionSides)</tt><br>
 * <tt>%JunctionSides operator^(JunctionSides, JunctionSides)</tt><br>
 * <tt>%JunctionSides operator~(JunctionSides)</tt><br>
 * <tt>%JunctionSides& operator|=(JunctionSides&, JunctionSides)</tt><br>
 * <tt>%JunctionSides& operator&=(JunctionSides&, JunctionSides)</tt><br>
 * <tt>%JunctionSides& operator^=(JunctionSides&, JunctionSides)</tt><br>
 */
enum JunctionSides
{
  JUNCTION_NONE = 0x0,
  JUNCTION_CORNER_TOPLEFT = 1 << 0,
  JUNCTION_CORNER_TOPRIGHT = 1 << 1,
  JUNCTION_CORNER_BOTTOMLEFT = 1 << 2,
  JUNCTION_CORNER_BOTTOMRIGHT = 1 << 3,
  JUNCTION_TOP = 0x3,
  JUNCTION_BOTTOM = 0xC,
  JUNCTION_LEFT = 0x5,
  JUNCTION_RIGHT = 0xA
};

/** @ingroup gtkmmEnums */
inline JunctionSides operator|(JunctionSides lhs, JunctionSides rhs)
  { return static_cast<JunctionSides>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline JunctionSides operator&(JunctionSides lhs, JunctionSides rhs)
  { return static_cast<JunctionSides>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline JunctionSides operator^(JunctionSides lhs, JunctionSides rhs)
  { return static_cast<JunctionSides>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline JunctionSides operator~(JunctionSides flags)
  { return static_cast<JunctionSides>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline JunctionSides& operator|=(JunctionSides& lhs, JunctionSides rhs)
  { return (lhs = static_cast<JunctionSides>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline JunctionSides& operator&=(JunctionSides& lhs, JunctionSides rhs)
  { return (lhs = static_cast<JunctionSides>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline JunctionSides& operator^=(JunctionSides& lhs, JunctionSides rhs)
  { return (lhs = static_cast<JunctionSides>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::JunctionSides> : public Glib::Value_Flags<Gtk::JunctionSides>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%StateFlags operator|(StateFlags, StateFlags)</tt><br>
 * <tt>%StateFlags operator&(StateFlags, StateFlags)</tt><br>
 * <tt>%StateFlags operator^(StateFlags, StateFlags)</tt><br>
 * <tt>%StateFlags operator~(StateFlags)</tt><br>
 * <tt>%StateFlags& operator|=(StateFlags&, StateFlags)</tt><br>
 * <tt>%StateFlags& operator&=(StateFlags&, StateFlags)</tt><br>
 * <tt>%StateFlags& operator^=(StateFlags&, StateFlags)</tt><br>
 */
enum StateFlags
{
  STATE_FLAG_NORMAL = 0x0,
  STATE_FLAG_ACTIVE = 1 << 0,
  STATE_FLAG_PRELIGHT = 1 << 1,
  STATE_FLAG_SELECTED = 1 << 2,
  STATE_FLAG_INSENSITIVE = 1 << 3,
  STATE_FLAG_INCONSISTENT = 1 << 4,
  STATE_FLAG_FOCUSED = 1 << 5,
  STATE_FLAG_BACKDROP = 1 << 6
};

/** @ingroup gtkmmEnums */
inline StateFlags operator|(StateFlags lhs, StateFlags rhs)
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline StateFlags operator&(StateFlags lhs, StateFlags rhs)
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline StateFlags operator^(StateFlags lhs, StateFlags rhs)
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline StateFlags operator~(StateFlags flags)
  { return static_cast<StateFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline StateFlags& operator|=(StateFlags& lhs, StateFlags rhs)
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline StateFlags& operator&=(StateFlags& lhs, StateFlags rhs)
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline StateFlags& operator^=(StateFlags& lhs, StateFlags rhs)
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::StateFlags> : public Glib::Value_Flags<Gtk::StateFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum InputPurpose
{
  INPUT_PURPOSE_FREE_FORM,
  INPUT_PURPOSE_ALPHA,
  INPUT_PURPOSE_DIGITS,
  INPUT_PURPOSE_NUMBER,
  INPUT_PURPOSE_PHONE,
  INPUT_PURPOSE_URL,
  INPUT_PURPOSE_EMAIL,
  INPUT_PURPOSE_NAME,
  INPUT_PURPOSE_PASSWORD,
  INPUT_PURPOSE_PIN
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::InputPurpose> : public Glib::Value_Enum<Gtk::InputPurpose>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%InputHints operator|(InputHints, InputHints)</tt><br>
 * <tt>%InputHints operator&(InputHints, InputHints)</tt><br>
 * <tt>%InputHints operator^(InputHints, InputHints)</tt><br>
 * <tt>%InputHints operator~(InputHints)</tt><br>
 * <tt>%InputHints& operator|=(InputHints&, InputHints)</tt><br>
 * <tt>%InputHints& operator&=(InputHints&, InputHints)</tt><br>
 * <tt>%InputHints& operator^=(InputHints&, InputHints)</tt><br>
 */
enum InputHints
{
  INPUT_HINT_NONE = 0x0,
  INPUT_HINT_SPELLCHECK = 1 << 0,
  INPUT_HINT_NO_SPELLCHECK = 1 << 1,
  INPUT_HINT_WORD_COMPLETION = 1 << 2,
  INPUT_HINT_LOWERCASE = 1 << 3,
  INPUT_HINT_UPPERCASE_CHARS = 1 << 4,
  INPUT_HINT_UPPERCASE_WORDS = 1 << 5,
  INPUT_HINT_UPPERCASE_SENTENCES = 1 << 6,
  INPUT_HINT_INHIBIT_OSK = 1 << 7
};

/** @ingroup gtkmmEnums */
inline InputHints operator|(InputHints lhs, InputHints rhs)
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline InputHints operator&(InputHints lhs, InputHints rhs)
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline InputHints operator^(InputHints lhs, InputHints rhs)
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline InputHints operator~(InputHints flags)
  { return static_cast<InputHints>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline InputHints& operator|=(InputHints& lhs, InputHints rhs)
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline InputHints& operator&=(InputHints& lhs, InputHints rhs)
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline InputHints& operator^=(InputHints& lhs, InputHints rhs)
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::InputHints> : public Glib::Value_Flags<Gtk::InputHints>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/* We use a class to implement the GtkIconSize enum, because you can register
 * new "enum" values.  The strict type rules of C++ don't allow using an enum
 * like that.  Gtk::BuiltinIconSize is the actual GtkIconSize wrapper enum.
 */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class Settings;
#endif //DOXYGEN_SHOULD_SKIP_THIS

/**
 * Represents registered icon sizes.
 * You can also use a Gtk::BuiltinIconSize instead of an IconSize.
 */
class IconSize
{
private:
  int size_;

public:
  IconSize()                     : size_ (0)    {}
  IconSize(BuiltinIconSize size) : size_ (size) {}

  // Behave like an ordinary enum.
  explicit IconSize(int size) : size_ (size) {}
  operator int() const { return size_; }

  // These static methods are implemented in iconfactory.ccg. TODO: That's probably unnecessarily obscure. murrayc.

  /** Obtains the pixel size of a semantic icon size, possibly modified by user preferences for the default Gtk::Settings.
   * Normally size would be Gtk::ICON_SIZE_MENU, Gtk::ICON_SIZE_BUTTON, etc.
   * This function isn't normally needed because Gtk::Widget::render_icon() is the usual way to get an icon for
   * rendering - then just look at the size of the rendered pixbuf. The rendered pixbuf may not even correspond
   * to the width/height returned by IconSize::lookup(), because themes are free to render the pixbuf however they
   * like, including changing the usual size.
   *
   * @param size An icon size.
   * @param width Location to store icon width.
   * @param height Location to store icon height.
   * @result true if size was a valid size.
   */
  static bool lookup(IconSize size, int& width, int& height);

  /** Obtains the pixel size of a semantic icon size, possibly modified by user preferences for a particular
   * Gtk::Settings. Normally size would be Gtk::ICON_SIZE_MENU, Gtk::ICON_SIZE_BUTTON, etc.
   * This function isn't normally needed because Gtk::Widget::render_icon() is the usual way to get an icon for
   * rendering - then just look at the size of the rendered pixbuf. The rendered pixbuf may not even correspond
   * to the width/height returned by IconSize::lookup(), because themes are free to render the pixbuf however they
   * like, including changing the usual size.
   *
   * @param size An icon size.
   * @param width Location to store icon width.
   * @param height Location to store icon height.
   * @param settings A Gtk::Settings object, used to determine which set of user preferences to used.
   * @result true if size was a valid size.
   *
   * @newin{2,14}
   */
  static bool lookup(IconSize size, int& width, int& height, const Glib::RefPtr<Gtk::Settings>& settings);

  /** Registers a new icon size, along the same lines as ICON_SIZE_MENU, etc. Returns the integer value for the size.
   *
   * @param	name Name of the icon size.
   * @param width The icon width.
   * @param height The icon height.
   * @result Integer value representing the size.
   */
  static IconSize register_new(const Glib::ustring& name, int width, int height);

  /** Registers @a alias as another name for @a target so calling from_name() with @a alias as argument will return @a target.
   *
   * @param alias An alias for target.
   * @param target An existing icon size.
   */
  static void register_alias(const Glib::ustring& alias, IconSize target);

  /** Looks up the icon size associated with @a name.
   *
   * @param name the name to look up.
   * result The icon size with the given name.
   */
  static IconSize from_name(const Glib::ustring& name);

  /** Gets the canonical name of the given icon size.
   *
   * @param size size AnIconSize.
   * @result The name of the given icon size.
   */
  static Glib::ustring get_name(IconSize size);
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct IconSizeTraits
{
  typedef Gtk::IconSize CppType;
  typedef GtkIconSize   CType;
  typedef GtkIconSize   CTypeNonConst;

  static CType   to_c_type      (CType c_obj)            { return c_obj; }
  static void    release_c_type (CType)                  {}
  static CType   to_c_type      (const CppType& cpp_obj) { int value (cpp_obj); return static_cast<CType> (value); }
  static CppType to_cpp_type    (CType c_obj)            { return CppType (c_obj); }
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::IconSize> : public Glib::Value_Enum<Gtk::IconSize>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
//We need this because we can't just use floats for enum value.
float _gtkmm_align_float_from_enum(Align value);
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} //namespace Gtk


#endif /* _GTKMM_ENUMS_H */

