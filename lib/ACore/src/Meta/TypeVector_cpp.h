
#ifndef META__TypeVector_CPP_H
#define META__TypeVector_CPP_H

namespace Meta {

#define TEMPLATE_DEF template <typename ElementType,int Length>
#define TYPE_DEF TypeVector<ElementType,Length>

TEMPLATE_DEF void TYPE_DEF::setAs(const ThisType    &_vector){value=_vector.value;parent.setAs(_vector.parent);}
TEMPLATE_DEF void TYPE_DEF::setAs(const ElementType &_scalar){value=_scalar      ;parent.setAs(_s