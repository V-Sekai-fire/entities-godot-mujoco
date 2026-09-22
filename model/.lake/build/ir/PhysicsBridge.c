// Lean compiler output
// Module: PhysicsBridge
// Imports: public import Init public meta import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Std_Format_fill(lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_instDecidableEqNat___boxed(lean_object*, lean_object*);
uint8_t l_instDecidableEqList___redArg(lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_get_x3fInternal___redArg(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqReg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqReg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0(lean_object*, lean_object*);
static const lean_string_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "[]"};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__0 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__0_value;
static const lean_ctor_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__0_value)}};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__1 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__1_value;
static const lean_string_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "["};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__2 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__2_value;
static const lean_string_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__3 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__3_value;
static const lean_ctor_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__3_value)}};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4_value;
static const lean_ctor_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__5 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__5_value;
static const lean_string_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__6 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__6_value;
static lean_once_cell_t lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7;
static lean_once_cell_t lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8;
static const lean_ctor_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__2_value)}};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__9 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__9_value;
static const lean_ctor_object lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__6_value)}};
static const lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__10 = (const lean_object*)&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__10_value;
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg(lean_object*);
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__0_value;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "bodies"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__1 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__1_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__1_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__2 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__2_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__2_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__3 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__3_value;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__4 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__4_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__4_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__3_value),((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__6 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__6_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "nextRid"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__8 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__8_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__8_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__9 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__9_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__11 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__11_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__0_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__14 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__14_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__11_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__15 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__15_value;
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_physicsbridge_PhysicsBridge_instReprReg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_physicsbridge_PhysicsBridge_instReprReg_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg___closed__0_value;
LEAN_EXPORT const lean_object* lp_physicsbridge_PhysicsBridge_instReprReg = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg___closed__0_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_empty___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_physicsbridge_PhysicsBridge_empty___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_empty___closed__0_value;
LEAN_EXPORT const lean_object* lp_physicsbridge_PhysicsBridge_empty = (const lean_object*)&lp_physicsbridge_PhysicsBridge_empty___closed__0_value;
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_create(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_ridAt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_ridAt___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_indexOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_indexOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_createN(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_createN___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_Phase_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqPhase(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqPhase___boxed(lean_object*, lean_object*);
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "PhysicsBridge.Phase.building"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__0_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__0_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__1 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__1_value;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "PhysicsBridge.Phase.compiled"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__2 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__2_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__2_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__3 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__3_value;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "PhysicsBridge.Phase.dirty"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__4 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__4_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__4_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__5 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__5_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7;
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_physicsbridge_PhysicsBridge_instReprPhase___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_physicsbridge_PhysicsBridge_instReprPhase_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase___closed__0_value;
LEAN_EXPORT const lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprPhase___closed__0_value;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "reg"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__0_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__0_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__1 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__1_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__1_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__2 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__2_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__2_value),((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__3 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__3_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4;
static const lean_string_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "phase"};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__5 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__5_value;
static const lean_ctor_object lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__5_value)}};
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__6 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__6_value;
static lean_once_cell_t lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7;
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_physicsbridge_PhysicsBridge_instReprBridge___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_physicsbridge_PhysicsBridge_instReprBridge_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge___closed__0 = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge___closed__0_value;
LEAN_EXPORT const lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge = (const lean_object*)&lp_physicsbridge_PhysicsBridge_instReprBridge___closed__0_value;
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_create(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_free(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_free___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_compile(lean_object*);
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_step(lean_object*);
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq(lean_object* v_x_1_, lean_object* v_x_2_){
_start:
{
lean_object* v_bodies_3_; lean_object* v_nextRid_4_; lean_object* v_bodies_5_; lean_object* v_nextRid_6_; lean_object* v___x_7_; uint8_t v___x_8_; 
v_bodies_3_ = lean_ctor_get(v_x_1_, 0);
lean_inc(v_bodies_3_);
v_nextRid_4_ = lean_ctor_get(v_x_1_, 1);
lean_inc(v_nextRid_4_);
lean_dec_ref(v_x_1_);
v_bodies_5_ = lean_ctor_get(v_x_2_, 0);
lean_inc(v_bodies_5_);
v_nextRid_6_ = lean_ctor_get(v_x_2_, 1);
lean_inc(v_nextRid_6_);
lean_dec_ref(v_x_2_);
v___x_7_ = lean_alloc_closure((void*)(l_instDecidableEqNat___boxed), 2, 0);
v___x_8_ = l_instDecidableEqList___redArg(v___x_7_, v_bodies_3_, v_bodies_5_);
if (v___x_8_ == 0)
{
lean_dec(v_nextRid_6_);
lean_dec(v_nextRid_4_);
return v___x_8_;
}
else
{
uint8_t v___x_9_; 
v___x_9_ = lean_nat_dec_eq(v_nextRid_4_, v_nextRid_6_);
lean_dec(v_nextRid_6_);
lean_dec(v_nextRid_4_);
return v___x_9_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq___boxed(lean_object* v_x_10_, lean_object* v_x_11_){
_start:
{
uint8_t v_res_12_; lean_object* v_r_13_; 
v_res_12_ = lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq(v_x_10_, v_x_11_);
v_r_13_ = lean_box(v_res_12_);
return v_r_13_;
}
}
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqReg(lean_object* v_x_14_, lean_object* v_x_15_){
_start:
{
uint8_t v___x_16_; 
v___x_16_ = lp_physicsbridge_PhysicsBridge_instDecidableEqReg_decEq(v_x_14_, v_x_15_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqReg___boxed(lean_object* v_x_17_, lean_object* v_x_18_){
_start:
{
uint8_t v_res_19_; lean_object* v_r_20_; 
v_res_19_ = lp_physicsbridge_PhysicsBridge_instDecidableEqReg(v_x_17_, v_x_18_);
v_r_20_ = lean_box(v_res_19_);
return v_r_20_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0___lam__0(lean_object* v___y_21_){
_start:
{
lean_object* v___x_22_; lean_object* v___x_23_; 
v___x_22_ = l_Nat_reprFast(v___y_21_);
v___x_23_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_23_, 0, v___x_22_);
return v___x_23_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1_spec__2(lean_object* v_x_24_, lean_object* v_x_25_, lean_object* v_x_26_){
_start:
{
if (lean_obj_tag(v_x_26_) == 0)
{
lean_dec(v_x_24_);
return v_x_25_;
}
else
{
lean_object* v_head_27_; lean_object* v_tail_28_; lean_object* v___x_30_; uint8_t v_isShared_31_; uint8_t v_isSharedCheck_39_; 
v_head_27_ = lean_ctor_get(v_x_26_, 0);
v_tail_28_ = lean_ctor_get(v_x_26_, 1);
v_isSharedCheck_39_ = !lean_is_exclusive(v_x_26_);
if (v_isSharedCheck_39_ == 0)
{
v___x_30_ = v_x_26_;
v_isShared_31_ = v_isSharedCheck_39_;
goto v_resetjp_29_;
}
else
{
lean_inc(v_tail_28_);
lean_inc(v_head_27_);
lean_dec(v_x_26_);
v___x_30_ = lean_box(0);
v_isShared_31_ = v_isSharedCheck_39_;
goto v_resetjp_29_;
}
v_resetjp_29_:
{
lean_object* v___x_33_; 
lean_inc(v_x_24_);
if (v_isShared_31_ == 0)
{
lean_ctor_set_tag(v___x_30_, 5);
lean_ctor_set(v___x_30_, 1, v_x_24_);
lean_ctor_set(v___x_30_, 0, v_x_25_);
v___x_33_ = v___x_30_;
goto v_reusejp_32_;
}
else
{
lean_object* v_reuseFailAlloc_38_; 
v_reuseFailAlloc_38_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_38_, 0, v_x_25_);
lean_ctor_set(v_reuseFailAlloc_38_, 1, v_x_24_);
v___x_33_ = v_reuseFailAlloc_38_;
goto v_reusejp_32_;
}
v_reusejp_32_:
{
lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; 
v___x_34_ = l_Nat_reprFast(v_head_27_);
v___x_35_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_35_, 0, v___x_34_);
v___x_36_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_36_, 0, v___x_33_);
lean_ctor_set(v___x_36_, 1, v___x_35_);
v_x_25_ = v___x_36_;
v_x_26_ = v_tail_28_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1(lean_object* v_x_40_, lean_object* v_x_41_, lean_object* v_x_42_){
_start:
{
if (lean_obj_tag(v_x_42_) == 0)
{
lean_dec(v_x_40_);
return v_x_41_;
}
else
{
lean_object* v_head_43_; lean_object* v_tail_44_; lean_object* v___x_46_; uint8_t v_isShared_47_; uint8_t v_isSharedCheck_55_; 
v_head_43_ = lean_ctor_get(v_x_42_, 0);
v_tail_44_ = lean_ctor_get(v_x_42_, 1);
v_isSharedCheck_55_ = !lean_is_exclusive(v_x_42_);
if (v_isSharedCheck_55_ == 0)
{
v___x_46_ = v_x_42_;
v_isShared_47_ = v_isSharedCheck_55_;
goto v_resetjp_45_;
}
else
{
lean_inc(v_tail_44_);
lean_inc(v_head_43_);
lean_dec(v_x_42_);
v___x_46_ = lean_box(0);
v_isShared_47_ = v_isSharedCheck_55_;
goto v_resetjp_45_;
}
v_resetjp_45_:
{
lean_object* v___x_49_; 
lean_inc(v_x_40_);
if (v_isShared_47_ == 0)
{
lean_ctor_set_tag(v___x_46_, 5);
lean_ctor_set(v___x_46_, 1, v_x_40_);
lean_ctor_set(v___x_46_, 0, v_x_41_);
v___x_49_ = v___x_46_;
goto v_reusejp_48_;
}
else
{
lean_object* v_reuseFailAlloc_54_; 
v_reuseFailAlloc_54_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_54_, 0, v_x_41_);
lean_ctor_set(v_reuseFailAlloc_54_, 1, v_x_40_);
v___x_49_ = v_reuseFailAlloc_54_;
goto v_reusejp_48_;
}
v_reusejp_48_:
{
lean_object* v___x_50_; lean_object* v___x_51_; lean_object* v___x_52_; lean_object* v___x_53_; 
v___x_50_ = l_Nat_reprFast(v_head_43_);
v___x_51_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_51_, 0, v___x_50_);
v___x_52_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_52_, 0, v___x_49_);
lean_ctor_set(v___x_52_, 1, v___x_51_);
v___x_53_ = lp_physicsbridge_List_foldl___at___00List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1_spec__2(v_x_40_, v___x_52_, v_tail_44_);
return v___x_53_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0(lean_object* v_x_56_, lean_object* v_x_57_){
_start:
{
if (lean_obj_tag(v_x_56_) == 0)
{
lean_object* v___x_58_; 
lean_dec(v_x_57_);
v___x_58_ = lean_box(0);
return v___x_58_;
}
else
{
lean_object* v_tail_59_; 
v_tail_59_ = lean_ctor_get(v_x_56_, 1);
if (lean_obj_tag(v_tail_59_) == 0)
{
lean_object* v_head_60_; lean_object* v___x_61_; 
lean_dec(v_x_57_);
v_head_60_ = lean_ctor_get(v_x_56_, 0);
lean_inc(v_head_60_);
lean_dec_ref_known(v_x_56_, 2);
v___x_61_ = lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0___lam__0(v_head_60_);
return v___x_61_;
}
else
{
lean_object* v_head_62_; lean_object* v___x_63_; lean_object* v___x_64_; 
lean_inc(v_tail_59_);
v_head_62_ = lean_ctor_get(v_x_56_, 0);
lean_inc(v_head_62_);
lean_dec_ref_known(v_x_56_, 2);
v___x_63_ = lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0___lam__0(v_head_62_);
v___x_64_ = lp_physicsbridge_List_foldl___at___00Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0_spec__1(v_x_57_, v___x_63_, v_tail_59_);
return v___x_64_;
}
}
}
}
static lean_object* _init_lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7(void){
_start:
{
lean_object* v___x_76_; lean_object* v___x_77_; 
v___x_76_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__2));
v___x_77_ = lean_string_length(v___x_76_);
return v___x_77_;
}
}
static lean_object* _init_lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8(void){
_start:
{
lean_object* v___x_78_; lean_object* v___x_79_; 
v___x_78_ = lean_obj_once(&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7, &lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7_once, _init_lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__7);
v___x_79_ = lean_nat_to_int(v___x_78_);
return v___x_79_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg(lean_object* v_a_84_){
_start:
{
if (lean_obj_tag(v_a_84_) == 0)
{
lean_object* v___x_85_; 
v___x_85_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__1));
return v___x_85_;
}
else
{
lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; 
v___x_86_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__5));
v___x_87_ = lp_physicsbridge_Std_Format_joinSep___at___00List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0_spec__0(v_a_84_, v___x_86_);
v___x_88_ = lean_obj_once(&lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8, &lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8_once, _init_lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__8);
v___x_89_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__9));
v___x_90_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_90_, 0, v___x_89_);
lean_ctor_set(v___x_90_, 1, v___x_87_);
v___x_91_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__10));
v___x_92_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_92_, 0, v___x_90_);
lean_ctor_set(v___x_92_, 1, v___x_91_);
v___x_93_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_93_, 0, v___x_88_);
lean_ctor_set(v___x_93_, 1, v___x_92_);
v___x_94_ = l_Std_Format_fill(v___x_93_);
return v___x_94_;
}
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_108_; lean_object* v___x_109_; 
v___x_108_ = lean_unsigned_to_nat(10u);
v___x_109_ = lean_nat_to_int(v___x_108_);
return v___x_109_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10(void){
_start:
{
lean_object* v___x_113_; lean_object* v___x_114_; 
v___x_113_ = lean_unsigned_to_nat(11u);
v___x_114_ = lean_nat_to_int(v___x_113_);
return v___x_114_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12(void){
_start:
{
lean_object* v___x_116_; lean_object* v___x_117_; 
v___x_116_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__0));
v___x_117_ = lean_string_length(v___x_116_);
return v___x_117_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_118_; lean_object* v___x_119_; 
v___x_118_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12, &lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12_once, _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__12);
v___x_119_ = lean_nat_to_int(v___x_118_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg(lean_object* v_x_124_){
_start:
{
lean_object* v_bodies_125_; lean_object* v_nextRid_126_; lean_object* v___x_128_; uint8_t v_isShared_129_; uint8_t v_isSharedCheck_160_; 
v_bodies_125_ = lean_ctor_get(v_x_124_, 0);
v_nextRid_126_ = lean_ctor_get(v_x_124_, 1);
v_isSharedCheck_160_ = !lean_is_exclusive(v_x_124_);
if (v_isSharedCheck_160_ == 0)
{
v___x_128_ = v_x_124_;
v_isShared_129_ = v_isSharedCheck_160_;
goto v_resetjp_127_;
}
else
{
lean_inc(v_nextRid_126_);
lean_inc(v_bodies_125_);
lean_dec(v_x_124_);
v___x_128_ = lean_box(0);
v_isShared_129_ = v_isSharedCheck_160_;
goto v_resetjp_127_;
}
v_resetjp_127_:
{
lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_135_; 
v___x_130_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5));
v___x_131_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__6));
v___x_132_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7, &lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7_once, _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__7);
v___x_133_ = lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg(v_bodies_125_);
if (v_isShared_129_ == 0)
{
lean_ctor_set_tag(v___x_128_, 4);
lean_ctor_set(v___x_128_, 1, v___x_133_);
lean_ctor_set(v___x_128_, 0, v___x_132_);
v___x_135_ = v___x_128_;
goto v_reusejp_134_;
}
else
{
lean_object* v_reuseFailAlloc_159_; 
v_reuseFailAlloc_159_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_159_, 0, v___x_132_);
lean_ctor_set(v_reuseFailAlloc_159_, 1, v___x_133_);
v___x_135_ = v_reuseFailAlloc_159_;
goto v_reusejp_134_;
}
v_reusejp_134_:
{
uint8_t v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; 
v___x_136_ = 0;
v___x_137_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_137_, 0, v___x_135_);
lean_ctor_set_uint8(v___x_137_, sizeof(void*)*1, v___x_136_);
v___x_138_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_138_, 0, v___x_131_);
lean_ctor_set(v___x_138_, 1, v___x_137_);
v___x_139_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4));
v___x_140_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_140_, 0, v___x_138_);
lean_ctor_set(v___x_140_, 1, v___x_139_);
v___x_141_ = lean_box(1);
v___x_142_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_142_, 0, v___x_140_);
lean_ctor_set(v___x_142_, 1, v___x_141_);
v___x_143_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__9));
v___x_144_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_144_, 0, v___x_142_);
lean_ctor_set(v___x_144_, 1, v___x_143_);
v___x_145_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_145_, 0, v___x_144_);
lean_ctor_set(v___x_145_, 1, v___x_130_);
v___x_146_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10, &lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10_once, _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__10);
v___x_147_ = l_Nat_reprFast(v_nextRid_126_);
v___x_148_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_148_, 0, v___x_147_);
v___x_149_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_149_, 0, v___x_146_);
lean_ctor_set(v___x_149_, 1, v___x_148_);
v___x_150_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_150_, 0, v___x_149_);
lean_ctor_set_uint8(v___x_150_, sizeof(void*)*1, v___x_136_);
v___x_151_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_151_, 0, v___x_145_);
lean_ctor_set(v___x_151_, 1, v___x_150_);
v___x_152_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13, &lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13_once, _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13);
v___x_153_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__14));
v___x_154_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_154_, 0, v___x_153_);
lean_ctor_set(v___x_154_, 1, v___x_151_);
v___x_155_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__15));
v___x_156_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_156_, 0, v___x_154_);
lean_ctor_set(v___x_156_, 1, v___x_155_);
v___x_157_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_157_, 0, v___x_152_);
lean_ctor_set(v___x_157_, 1, v___x_156_);
v___x_158_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_158_, 0, v___x_157_);
lean_ctor_set_uint8(v___x_158_, sizeof(void*)*1, v___x_136_);
return v___x_158_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr(lean_object* v_x_161_, lean_object* v_prec_162_){
_start:
{
lean_object* v___x_163_; 
v___x_163_ = lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg(v_x_161_);
return v___x_163_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprReg_repr___boxed(lean_object* v_x_164_, lean_object* v_prec_165_){
_start:
{
lean_object* v_res_166_; 
v_res_166_ = lp_physicsbridge_PhysicsBridge_instReprReg_repr(v_x_164_, v_prec_165_);
lean_dec(v_prec_165_);
return v_res_166_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0(lean_object* v_a_167_, lean_object* v_n_168_){
_start:
{
lean_object* v___x_169_; 
v___x_169_ = lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg(v_a_167_);
return v___x_169_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___boxed(lean_object* v_a_170_, lean_object* v_n_171_){
_start:
{
lean_object* v_res_172_; 
v_res_172_ = lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0(v_a_170_, v_n_171_);
lean_dec(v_n_171_);
return v_res_172_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_create(lean_object* v_r_179_){
_start:
{
lean_object* v_bodies_180_; lean_object* v_nextRid_181_; lean_object* v___x_183_; uint8_t v_isShared_184_; uint8_t v_isSharedCheck_194_; 
v_bodies_180_ = lean_ctor_get(v_r_179_, 0);
v_nextRid_181_ = lean_ctor_get(v_r_179_, 1);
v_isSharedCheck_194_ = !lean_is_exclusive(v_r_179_);
if (v_isSharedCheck_194_ == 0)
{
v___x_183_ = v_r_179_;
v_isShared_184_ = v_isSharedCheck_194_;
goto v_resetjp_182_;
}
else
{
lean_inc(v_nextRid_181_);
lean_inc(v_bodies_180_);
lean_dec(v_r_179_);
v___x_183_ = lean_box(0);
v_isShared_184_ = v_isSharedCheck_194_;
goto v_resetjp_182_;
}
v_resetjp_182_:
{
lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_191_; 
v___x_185_ = lean_box(0);
lean_inc(v_nextRid_181_);
v___x_186_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_186_, 0, v_nextRid_181_);
lean_ctor_set(v___x_186_, 1, v___x_185_);
v___x_187_ = l_List_appendTR___redArg(v_bodies_180_, v___x_186_);
v___x_188_ = lean_unsigned_to_nat(1u);
v___x_189_ = lean_nat_add(v_nextRid_181_, v___x_188_);
if (v_isShared_184_ == 0)
{
lean_ctor_set(v___x_183_, 1, v___x_189_);
lean_ctor_set(v___x_183_, 0, v___x_187_);
v___x_191_ = v___x_183_;
goto v_reusejp_190_;
}
else
{
lean_object* v_reuseFailAlloc_193_; 
v_reuseFailAlloc_193_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_193_, 0, v___x_187_);
lean_ctor_set(v_reuseFailAlloc_193_, 1, v___x_189_);
v___x_191_ = v_reuseFailAlloc_193_;
goto v_reusejp_190_;
}
v_reusejp_190_:
{
lean_object* v___x_192_; 
v___x_192_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_192_, 0, v_nextRid_181_);
lean_ctor_set(v___x_192_, 1, v___x_191_);
return v___x_192_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_ridAt(lean_object* v_r_195_, lean_object* v_i_196_){
_start:
{
lean_object* v_bodies_197_; lean_object* v___x_198_; 
v_bodies_197_ = lean_ctor_get(v_r_195_, 0);
v___x_198_ = l_List_get_x3fInternal___redArg(v_bodies_197_, v_i_196_);
return v___x_198_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_ridAt___boxed(lean_object* v_r_199_, lean_object* v_i_200_){
_start:
{
lean_object* v_res_201_; 
v_res_201_ = lp_physicsbridge_PhysicsBridge_ridAt(v_r_199_, v_i_200_);
lean_dec_ref(v_r_199_);
return v_res_201_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0(lean_object* v_rid_202_, lean_object* v_a_203_, lean_object* v_a_204_){
_start:
{
if (lean_obj_tag(v_a_203_) == 0)
{
lean_object* v___x_205_; 
lean_dec(v_a_204_);
v___x_205_ = lean_box(0);
return v___x_205_;
}
else
{
lean_object* v_head_206_; lean_object* v_tail_207_; uint8_t v___x_208_; 
v_head_206_ = lean_ctor_get(v_a_203_, 0);
v_tail_207_ = lean_ctor_get(v_a_203_, 1);
v___x_208_ = lean_nat_dec_eq(v_head_206_, v_rid_202_);
if (v___x_208_ == 0)
{
lean_object* v___x_209_; lean_object* v___x_210_; 
v___x_209_ = lean_unsigned_to_nat(1u);
v___x_210_ = lean_nat_add(v_a_204_, v___x_209_);
lean_dec(v_a_204_);
v_a_203_ = v_tail_207_;
v_a_204_ = v___x_210_;
goto _start;
}
else
{
lean_object* v___x_212_; 
v___x_212_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_212_, 0, v_a_204_);
return v___x_212_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0___boxed(lean_object* v_rid_213_, lean_object* v_a_214_, lean_object* v_a_215_){
_start:
{
lean_object* v_res_216_; 
v_res_216_ = lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0(v_rid_213_, v_a_214_, v_a_215_);
lean_dec(v_a_214_);
lean_dec(v_rid_213_);
return v_res_216_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_indexOf(lean_object* v_r_217_, lean_object* v_rid_218_){
_start:
{
lean_object* v_bodies_219_; lean_object* v___x_220_; lean_object* v___x_221_; 
v_bodies_219_ = lean_ctor_get(v_r_217_, 0);
v___x_220_ = lean_unsigned_to_nat(0u);
v___x_221_ = lp_physicsbridge_List_findIdx_x3f_go___at___00PhysicsBridge_indexOf_spec__0(v_rid_218_, v_bodies_219_, v___x_220_);
return v___x_221_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_indexOf___boxed(lean_object* v_r_222_, lean_object* v_rid_223_){
_start:
{
lean_object* v_res_224_; 
v_res_224_ = lp_physicsbridge_PhysicsBridge_indexOf(v_r_222_, v_rid_223_);
lean_dec(v_rid_223_);
lean_dec_ref(v_r_222_);
return v_res_224_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_createN(lean_object* v_x_225_){
_start:
{
lean_object* v_zero_226_; uint8_t v_isZero_227_; 
v_zero_226_ = lean_unsigned_to_nat(0u);
v_isZero_227_ = lean_nat_dec_eq(v_x_225_, v_zero_226_);
if (v_isZero_227_ == 1)
{
lean_object* v___x_228_; 
v___x_228_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_empty));
return v___x_228_;
}
else
{
lean_object* v_one_229_; lean_object* v_n_230_; lean_object* v___x_231_; lean_object* v___x_232_; lean_object* v_snd_233_; 
v_one_229_ = lean_unsigned_to_nat(1u);
v_n_230_ = lean_nat_sub(v_x_225_, v_one_229_);
v___x_231_ = lp_physicsbridge_PhysicsBridge_createN(v_n_230_);
lean_dec(v_n_230_);
v___x_232_ = lp_physicsbridge_PhysicsBridge_create(v___x_231_);
v_snd_233_ = lean_ctor_get(v___x_232_, 1);
lean_inc(v_snd_233_);
lean_dec_ref(v___x_232_);
return v_snd_233_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_createN___boxed(lean_object* v_x_234_){
_start:
{
lean_object* v_res_235_; 
v_res_235_ = lp_physicsbridge_PhysicsBridge_createN(v_x_234_);
lean_dec(v_x_234_);
return v_res_235_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___redArg(lean_object* v_x_236_, lean_object* v_h__1_237_, lean_object* v_h__2_238_){
_start:
{
lean_object* v_zero_239_; uint8_t v_isZero_240_; 
v_zero_239_ = lean_unsigned_to_nat(0u);
v_isZero_240_ = lean_nat_dec_eq(v_x_236_, v_zero_239_);
if (v_isZero_240_ == 1)
{
lean_object* v___x_241_; lean_object* v___x_242_; 
lean_dec(v_h__2_238_);
v___x_241_ = lean_box(0);
v___x_242_ = lean_apply_1(v_h__1_237_, v___x_241_);
return v___x_242_;
}
else
{
lean_object* v_one_243_; lean_object* v_n_244_; lean_object* v___x_245_; 
lean_dec(v_h__1_237_);
v_one_243_ = lean_unsigned_to_nat(1u);
v_n_244_ = lean_nat_sub(v_x_236_, v_one_243_);
v___x_245_ = lean_apply_1(v_h__2_238_, v_n_244_);
return v___x_245_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___redArg___boxed(lean_object* v_x_246_, lean_object* v_h__1_247_, lean_object* v_h__2_248_){
_start:
{
lean_object* v_res_249_; 
v_res_249_ = lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___redArg(v_x_246_, v_h__1_247_, v_h__2_248_);
lean_dec(v_x_246_);
return v_res_249_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter(lean_object* v_motive_250_, lean_object* v_x_251_, lean_object* v_h__1_252_, lean_object* v_h__2_253_){
_start:
{
lean_object* v_zero_254_; uint8_t v_isZero_255_; 
v_zero_254_ = lean_unsigned_to_nat(0u);
v_isZero_255_ = lean_nat_dec_eq(v_x_251_, v_zero_254_);
if (v_isZero_255_ == 1)
{
lean_object* v___x_256_; lean_object* v___x_257_; 
lean_dec(v_h__2_253_);
v___x_256_ = lean_box(0);
v___x_257_ = lean_apply_1(v_h__1_252_, v___x_256_);
return v___x_257_;
}
else
{
lean_object* v_one_258_; lean_object* v_n_259_; lean_object* v___x_260_; 
lean_dec(v_h__1_252_);
v_one_258_ = lean_unsigned_to_nat(1u);
v_n_259_ = lean_nat_sub(v_x_251_, v_one_258_);
v___x_260_ = lean_apply_1(v_h__2_253_, v_n_259_);
return v___x_260_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter___boxed(lean_object* v_motive_261_, lean_object* v_x_262_, lean_object* v_h__1_263_, lean_object* v_h__2_264_){
_start:
{
lean_object* v_res_265_; 
v_res_265_ = lp_physicsbridge___private_PhysicsBridge_0__PhysicsBridge_createN_match__1_splitter(v_motive_261_, v_x_262_, v_h__1_263_, v_h__2_264_);
lean_dec(v_x_262_);
return v_res_265_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorIdx(uint8_t v_x_266_){
_start:
{
switch(v_x_266_)
{
case 0:
{
lean_object* v___x_267_; 
v___x_267_ = lean_unsigned_to_nat(0u);
return v___x_267_;
}
case 1:
{
lean_object* v___x_268_; 
v___x_268_ = lean_unsigned_to_nat(1u);
return v___x_268_;
}
default: 
{
lean_object* v___x_269_; 
v___x_269_ = lean_unsigned_to_nat(2u);
return v___x_269_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorIdx___boxed(lean_object* v_x_270_){
_start:
{
uint8_t v_x_boxed_271_; lean_object* v_res_272_; 
v_x_boxed_271_ = lean_unbox(v_x_270_);
v_res_272_ = lp_physicsbridge_PhysicsBridge_Phase_ctorIdx(v_x_boxed_271_);
return v_res_272_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___redArg(lean_object* v_k_273_){
_start:
{
lean_inc(v_k_273_);
return v_k_273_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___redArg___boxed(lean_object* v_k_274_){
_start:
{
lean_object* v_res_275_; 
v_res_275_ = lp_physicsbridge_PhysicsBridge_Phase_ctorElim___redArg(v_k_274_);
lean_dec(v_k_274_);
return v_res_275_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim(lean_object* v_motive_276_, lean_object* v_ctorIdx_277_, uint8_t v_t_278_, lean_object* v_h_279_, lean_object* v_k_280_){
_start:
{
lean_inc(v_k_280_);
return v_k_280_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ctorElim___boxed(lean_object* v_motive_281_, lean_object* v_ctorIdx_282_, lean_object* v_t_283_, lean_object* v_h_284_, lean_object* v_k_285_){
_start:
{
uint8_t v_t_boxed_286_; lean_object* v_res_287_; 
v_t_boxed_286_ = lean_unbox(v_t_283_);
v_res_287_ = lp_physicsbridge_PhysicsBridge_Phase_ctorElim(v_motive_281_, v_ctorIdx_282_, v_t_boxed_286_, v_h_284_, v_k_285_);
lean_dec(v_k_285_);
lean_dec(v_ctorIdx_282_);
return v_res_287_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___redArg(lean_object* v_building_288_){
_start:
{
lean_inc(v_building_288_);
return v_building_288_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___redArg___boxed(lean_object* v_building_289_){
_start:
{
lean_object* v_res_290_; 
v_res_290_ = lp_physicsbridge_PhysicsBridge_Phase_building_elim___redArg(v_building_289_);
lean_dec(v_building_289_);
return v_res_290_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim(lean_object* v_motive_291_, uint8_t v_t_292_, lean_object* v_h_293_, lean_object* v_building_294_){
_start:
{
lean_inc(v_building_294_);
return v_building_294_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_building_elim___boxed(lean_object* v_motive_295_, lean_object* v_t_296_, lean_object* v_h_297_, lean_object* v_building_298_){
_start:
{
uint8_t v_t_boxed_299_; lean_object* v_res_300_; 
v_t_boxed_299_ = lean_unbox(v_t_296_);
v_res_300_ = lp_physicsbridge_PhysicsBridge_Phase_building_elim(v_motive_295_, v_t_boxed_299_, v_h_297_, v_building_298_);
lean_dec(v_building_298_);
return v_res_300_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___redArg(lean_object* v_compiled_301_){
_start:
{
lean_inc(v_compiled_301_);
return v_compiled_301_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___redArg___boxed(lean_object* v_compiled_302_){
_start:
{
lean_object* v_res_303_; 
v_res_303_ = lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___redArg(v_compiled_302_);
lean_dec(v_compiled_302_);
return v_res_303_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim(lean_object* v_motive_304_, uint8_t v_t_305_, lean_object* v_h_306_, lean_object* v_compiled_307_){
_start:
{
lean_inc(v_compiled_307_);
return v_compiled_307_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_compiled_elim___boxed(lean_object* v_motive_308_, lean_object* v_t_309_, lean_object* v_h_310_, lean_object* v_compiled_311_){
_start:
{
uint8_t v_t_boxed_312_; lean_object* v_res_313_; 
v_t_boxed_312_ = lean_unbox(v_t_309_);
v_res_313_ = lp_physicsbridge_PhysicsBridge_Phase_compiled_elim(v_motive_308_, v_t_boxed_312_, v_h_310_, v_compiled_311_);
lean_dec(v_compiled_311_);
return v_res_313_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___redArg(lean_object* v_dirty_314_){
_start:
{
lean_inc(v_dirty_314_);
return v_dirty_314_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___redArg___boxed(lean_object* v_dirty_315_){
_start:
{
lean_object* v_res_316_; 
v_res_316_ = lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___redArg(v_dirty_315_);
lean_dec(v_dirty_315_);
return v_res_316_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim(lean_object* v_motive_317_, uint8_t v_t_318_, lean_object* v_h_319_, lean_object* v_dirty_320_){
_start:
{
lean_inc(v_dirty_320_);
return v_dirty_320_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_dirty_elim___boxed(lean_object* v_motive_321_, lean_object* v_t_322_, lean_object* v_h_323_, lean_object* v_dirty_324_){
_start:
{
uint8_t v_t_boxed_325_; lean_object* v_res_326_; 
v_t_boxed_325_ = lean_unbox(v_t_322_);
v_res_326_ = lp_physicsbridge_PhysicsBridge_Phase_dirty_elim(v_motive_321_, v_t_boxed_325_, v_h_323_, v_dirty_324_);
lean_dec(v_dirty_324_);
return v_res_326_;
}
}
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_Phase_ofNat(lean_object* v_n_327_){
_start:
{
lean_object* v___x_328_; uint8_t v___x_329_; 
v___x_328_ = lean_unsigned_to_nat(0u);
v___x_329_ = lean_nat_dec_le(v_n_327_, v___x_328_);
if (v___x_329_ == 0)
{
lean_object* v___x_330_; uint8_t v___x_331_; 
v___x_330_ = lean_unsigned_to_nat(1u);
v___x_331_ = lean_nat_dec_le(v_n_327_, v___x_330_);
if (v___x_331_ == 0)
{
uint8_t v___x_332_; 
v___x_332_ = 2;
return v___x_332_;
}
else
{
uint8_t v___x_333_; 
v___x_333_ = 1;
return v___x_333_;
}
}
else
{
uint8_t v___x_334_; 
v___x_334_ = 0;
return v___x_334_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Phase_ofNat___boxed(lean_object* v_n_335_){
_start:
{
uint8_t v_res_336_; lean_object* v_r_337_; 
v_res_336_ = lp_physicsbridge_PhysicsBridge_Phase_ofNat(v_n_335_);
lean_dec(v_n_335_);
v_r_337_ = lean_box(v_res_336_);
return v_r_337_;
}
}
LEAN_EXPORT uint8_t lp_physicsbridge_PhysicsBridge_instDecidableEqPhase(uint8_t v_x_338_, uint8_t v_y_339_){
_start:
{
lean_object* v___x_340_; lean_object* v___x_341_; uint8_t v___x_342_; 
v___x_340_ = lp_physicsbridge_PhysicsBridge_Phase_ctorIdx(v_x_338_);
v___x_341_ = lp_physicsbridge_PhysicsBridge_Phase_ctorIdx(v_y_339_);
v___x_342_ = lean_nat_dec_eq(v___x_340_, v___x_341_);
lean_dec(v___x_341_);
lean_dec(v___x_340_);
return v___x_342_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instDecidableEqPhase___boxed(lean_object* v_x_343_, lean_object* v_y_344_){
_start:
{
uint8_t v_x_13__boxed_345_; uint8_t v_y_14__boxed_346_; uint8_t v_res_347_; lean_object* v_r_348_; 
v_x_13__boxed_345_ = lean_unbox(v_x_343_);
v_y_14__boxed_346_ = lean_unbox(v_y_344_);
v_res_347_ = lp_physicsbridge_PhysicsBridge_instDecidableEqPhase(v_x_13__boxed_345_, v_y_14__boxed_346_);
v_r_348_ = lean_box(v_res_347_);
return v_r_348_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6(void){
_start:
{
lean_object* v___x_358_; lean_object* v___x_359_; 
v___x_358_ = lean_unsigned_to_nat(2u);
v___x_359_ = lean_nat_to_int(v___x_358_);
return v___x_359_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7(void){
_start:
{
lean_object* v___x_360_; lean_object* v___x_361_; 
v___x_360_ = lean_unsigned_to_nat(1u);
v___x_361_ = lean_nat_to_int(v___x_360_);
return v___x_361_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr(uint8_t v_x_362_, lean_object* v_prec_363_){
_start:
{
lean_object* v___y_365_; lean_object* v___y_372_; lean_object* v___y_379_; 
switch(v_x_362_)
{
case 0:
{
lean_object* v___x_385_; uint8_t v___x_386_; 
v___x_385_ = lean_unsigned_to_nat(1024u);
v___x_386_ = lean_nat_dec_le(v___x_385_, v_prec_363_);
if (v___x_386_ == 0)
{
lean_object* v___x_387_; 
v___x_387_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6);
v___y_365_ = v___x_387_;
goto v___jp_364_;
}
else
{
lean_object* v___x_388_; 
v___x_388_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7);
v___y_365_ = v___x_388_;
goto v___jp_364_;
}
}
case 1:
{
lean_object* v___x_389_; uint8_t v___x_390_; 
v___x_389_ = lean_unsigned_to_nat(1024u);
v___x_390_ = lean_nat_dec_le(v___x_389_, v_prec_363_);
if (v___x_390_ == 0)
{
lean_object* v___x_391_; 
v___x_391_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6);
v___y_372_ = v___x_391_;
goto v___jp_371_;
}
else
{
lean_object* v___x_392_; 
v___x_392_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7);
v___y_372_ = v___x_392_;
goto v___jp_371_;
}
}
default: 
{
lean_object* v___x_393_; uint8_t v___x_394_; 
v___x_393_ = lean_unsigned_to_nat(1024u);
v___x_394_ = lean_nat_dec_le(v___x_393_, v_prec_363_);
if (v___x_394_ == 0)
{
lean_object* v___x_395_; 
v___x_395_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__6);
v___y_379_ = v___x_395_;
goto v___jp_378_;
}
else
{
lean_object* v___x_396_; 
v___x_396_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7, &lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7_once, _init_lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__7);
v___y_379_ = v___x_396_;
goto v___jp_378_;
}
}
}
v___jp_364_:
{
lean_object* v___x_366_; lean_object* v___x_367_; uint8_t v___x_368_; lean_object* v___x_369_; lean_object* v___x_370_; 
v___x_366_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__1));
lean_inc(v___y_365_);
v___x_367_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_367_, 0, v___y_365_);
lean_ctor_set(v___x_367_, 1, v___x_366_);
v___x_368_ = 0;
v___x_369_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_369_, 0, v___x_367_);
lean_ctor_set_uint8(v___x_369_, sizeof(void*)*1, v___x_368_);
v___x_370_ = l_Repr_addAppParen(v___x_369_, v_prec_363_);
return v___x_370_;
}
v___jp_371_:
{
lean_object* v___x_373_; lean_object* v___x_374_; uint8_t v___x_375_; lean_object* v___x_376_; lean_object* v___x_377_; 
v___x_373_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__3));
lean_inc(v___y_372_);
v___x_374_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_374_, 0, v___y_372_);
lean_ctor_set(v___x_374_, 1, v___x_373_);
v___x_375_ = 0;
v___x_376_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_376_, 0, v___x_374_);
lean_ctor_set_uint8(v___x_376_, sizeof(void*)*1, v___x_375_);
v___x_377_ = l_Repr_addAppParen(v___x_376_, v_prec_363_);
return v___x_377_;
}
v___jp_378_:
{
lean_object* v___x_380_; lean_object* v___x_381_; uint8_t v___x_382_; lean_object* v___x_383_; lean_object* v___x_384_; 
v___x_380_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprPhase_repr___closed__5));
lean_inc(v___y_379_);
v___x_381_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_381_, 0, v___y_379_);
lean_ctor_set(v___x_381_, 1, v___x_380_);
v___x_382_ = 0;
v___x_383_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_383_, 0, v___x_381_);
lean_ctor_set_uint8(v___x_383_, sizeof(void*)*1, v___x_382_);
v___x_384_ = l_Repr_addAppParen(v___x_383_, v_prec_363_);
return v___x_384_;
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprPhase_repr___boxed(lean_object* v_x_397_, lean_object* v_prec_398_){
_start:
{
uint8_t v_x_177__boxed_399_; lean_object* v_res_400_; 
v_x_177__boxed_399_ = lean_unbox(v_x_397_);
v_res_400_ = lp_physicsbridge_PhysicsBridge_instReprPhase_repr(v_x_177__boxed_399_, v_prec_398_);
lean_dec(v_prec_398_);
return v_res_400_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4(void){
_start:
{
lean_object* v___x_412_; lean_object* v___x_413_; 
v___x_412_ = lean_unsigned_to_nat(7u);
v___x_413_ = lean_nat_to_int(v___x_412_);
return v___x_413_;
}
}
static lean_object* _init_lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_417_; lean_object* v___x_418_; 
v___x_417_ = lean_unsigned_to_nat(9u);
v___x_418_ = lean_nat_to_int(v___x_417_);
return v___x_418_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg(lean_object* v_x_419_){
_start:
{
lean_object* v_reg_420_; uint8_t v_phase_421_; lean_object* v___x_423_; uint8_t v_isShared_424_; uint8_t v_isSharedCheck_455_; 
v_reg_420_ = lean_ctor_get(v_x_419_, 0);
v_phase_421_ = lean_ctor_get_uint8(v_x_419_, sizeof(void*)*1);
v_isSharedCheck_455_ = !lean_is_exclusive(v_x_419_);
if (v_isSharedCheck_455_ == 0)
{
v___x_423_ = v_x_419_;
v_isShared_424_ = v_isSharedCheck_455_;
goto v_resetjp_422_;
}
else
{
lean_inc(v_reg_420_);
lean_dec(v_x_419_);
v___x_423_ = lean_box(0);
v_isShared_424_ = v_isSharedCheck_455_;
goto v_resetjp_422_;
}
v_resetjp_422_:
{
lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; lean_object* v___x_428_; lean_object* v___x_429_; lean_object* v___x_430_; uint8_t v___x_431_; lean_object* v___x_433_; 
v___x_425_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__5));
v___x_426_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__3));
v___x_427_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4, &lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4_once, _init_lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__4);
v___x_428_ = lean_unsigned_to_nat(0u);
v___x_429_ = lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg(v_reg_420_);
v___x_430_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_430_, 0, v___x_427_);
lean_ctor_set(v___x_430_, 1, v___x_429_);
v___x_431_ = 0;
if (v_isShared_424_ == 0)
{
lean_ctor_set_tag(v___x_423_, 6);
lean_ctor_set(v___x_423_, 0, v___x_430_);
v___x_433_ = v___x_423_;
goto v_reusejp_432_;
}
else
{
lean_object* v_reuseFailAlloc_454_; 
v_reuseFailAlloc_454_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v_reuseFailAlloc_454_, 0, v___x_430_);
v___x_433_ = v_reuseFailAlloc_454_;
goto v_reusejp_432_;
}
v_reusejp_432_:
{
lean_object* v___x_434_; lean_object* v___x_435_; lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; lean_object* v___x_441_; lean_object* v___x_442_; lean_object* v___x_443_; lean_object* v___x_444_; lean_object* v___x_445_; lean_object* v___x_446_; lean_object* v___x_447_; lean_object* v___x_448_; lean_object* v___x_449_; lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_452_; lean_object* v___x_453_; 
lean_ctor_set_uint8(v___x_433_, sizeof(void*)*1, v___x_431_);
v___x_434_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_434_, 0, v___x_426_);
lean_ctor_set(v___x_434_, 1, v___x_433_);
v___x_435_ = ((lean_object*)(lp_physicsbridge_List_repr_x27___at___00PhysicsBridge_instReprReg_repr_spec__0___redArg___closed__4));
v___x_436_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_436_, 0, v___x_434_);
lean_ctor_set(v___x_436_, 1, v___x_435_);
v___x_437_ = lean_box(1);
v___x_438_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_438_, 0, v___x_436_);
lean_ctor_set(v___x_438_, 1, v___x_437_);
v___x_439_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__6));
v___x_440_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_440_, 0, v___x_438_);
lean_ctor_set(v___x_440_, 1, v___x_439_);
v___x_441_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_441_, 0, v___x_440_);
lean_ctor_set(v___x_441_, 1, v___x_425_);
v___x_442_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7, &lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7_once, _init_lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg___closed__7);
v___x_443_ = lp_physicsbridge_PhysicsBridge_instReprPhase_repr(v_phase_421_, v___x_428_);
v___x_444_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_444_, 0, v___x_442_);
lean_ctor_set(v___x_444_, 1, v___x_443_);
v___x_445_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_445_, 0, v___x_444_);
lean_ctor_set_uint8(v___x_445_, sizeof(void*)*1, v___x_431_);
v___x_446_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_446_, 0, v___x_441_);
lean_ctor_set(v___x_446_, 1, v___x_445_);
v___x_447_ = lean_obj_once(&lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13, &lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13_once, _init_lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__13);
v___x_448_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__14));
v___x_449_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_449_, 0, v___x_448_);
lean_ctor_set(v___x_449_, 1, v___x_446_);
v___x_450_ = ((lean_object*)(lp_physicsbridge_PhysicsBridge_instReprReg_repr___redArg___closed__15));
v___x_451_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_451_, 0, v___x_449_);
lean_ctor_set(v___x_451_, 1, v___x_450_);
v___x_452_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_452_, 0, v___x_447_);
lean_ctor_set(v___x_452_, 1, v___x_451_);
v___x_453_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_453_, 0, v___x_452_);
lean_ctor_set_uint8(v___x_453_, sizeof(void*)*1, v___x_431_);
return v___x_453_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr(lean_object* v_x_456_, lean_object* v_prec_457_){
_start:
{
lean_object* v___x_458_; 
v___x_458_ = lp_physicsbridge_PhysicsBridge_instReprBridge_repr___redArg(v_x_456_);
return v___x_458_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_instReprBridge_repr___boxed(lean_object* v_x_459_, lean_object* v_prec_460_){
_start:
{
lean_object* v_res_461_; 
v_res_461_ = lp_physicsbridge_PhysicsBridge_instReprBridge_repr(v_x_459_, v_prec_460_);
lean_dec(v_prec_460_);
return v_res_461_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_create(lean_object* v_b_464_){
_start:
{
lean_object* v_reg_465_; lean_object* v___x_467_; uint8_t v_isShared_468_; uint8_t v_isSharedCheck_475_; 
v_reg_465_ = lean_ctor_get(v_b_464_, 0);
v_isSharedCheck_475_ = !lean_is_exclusive(v_b_464_);
if (v_isSharedCheck_475_ == 0)
{
v___x_467_ = v_b_464_;
v_isShared_468_ = v_isSharedCheck_475_;
goto v_resetjp_466_;
}
else
{
lean_inc(v_reg_465_);
lean_dec(v_b_464_);
v___x_467_ = lean_box(0);
v_isShared_468_ = v_isSharedCheck_475_;
goto v_resetjp_466_;
}
v_resetjp_466_:
{
lean_object* v___x_469_; lean_object* v_snd_470_; uint8_t v___x_471_; lean_object* v___x_473_; 
v___x_469_ = lp_physicsbridge_PhysicsBridge_create(v_reg_465_);
v_snd_470_ = lean_ctor_get(v___x_469_, 1);
lean_inc(v_snd_470_);
lean_dec_ref(v___x_469_);
v___x_471_ = 2;
if (v_isShared_468_ == 0)
{
lean_ctor_set(v___x_467_, 0, v_snd_470_);
v___x_473_ = v___x_467_;
goto v_reusejp_472_;
}
else
{
lean_object* v_reuseFailAlloc_474_; 
v_reuseFailAlloc_474_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v_reuseFailAlloc_474_, 0, v_snd_470_);
v___x_473_ = v_reuseFailAlloc_474_;
goto v_reusejp_472_;
}
v_reusejp_472_:
{
lean_ctor_set_uint8(v___x_473_, sizeof(void*)*1, v___x_471_);
return v___x_473_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0(lean_object* v_rid_476_, lean_object* v_a_477_, lean_object* v_a_478_){
_start:
{
if (lean_obj_tag(v_a_477_) == 0)
{
lean_object* v___x_479_; 
v___x_479_ = l_List_reverse___redArg(v_a_478_);
return v___x_479_;
}
else
{
lean_object* v_head_480_; lean_object* v_tail_481_; lean_object* v___x_483_; uint8_t v_isShared_484_; uint8_t v_isSharedCheck_491_; 
v_head_480_ = lean_ctor_get(v_a_477_, 0);
v_tail_481_ = lean_ctor_get(v_a_477_, 1);
v_isSharedCheck_491_ = !lean_is_exclusive(v_a_477_);
if (v_isSharedCheck_491_ == 0)
{
v___x_483_ = v_a_477_;
v_isShared_484_ = v_isSharedCheck_491_;
goto v_resetjp_482_;
}
else
{
lean_inc(v_tail_481_);
lean_inc(v_head_480_);
lean_dec(v_a_477_);
v___x_483_ = lean_box(0);
v_isShared_484_ = v_isSharedCheck_491_;
goto v_resetjp_482_;
}
v_resetjp_482_:
{
uint8_t v___x_485_; 
v___x_485_ = lean_nat_dec_eq(v_head_480_, v_rid_476_);
if (v___x_485_ == 0)
{
lean_object* v___x_487_; 
if (v_isShared_484_ == 0)
{
lean_ctor_set(v___x_483_, 1, v_a_478_);
v___x_487_ = v___x_483_;
goto v_reusejp_486_;
}
else
{
lean_object* v_reuseFailAlloc_489_; 
v_reuseFailAlloc_489_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_489_, 0, v_head_480_);
lean_ctor_set(v_reuseFailAlloc_489_, 1, v_a_478_);
v___x_487_ = v_reuseFailAlloc_489_;
goto v_reusejp_486_;
}
v_reusejp_486_:
{
v_a_477_ = v_tail_481_;
v_a_478_ = v___x_487_;
goto _start;
}
}
else
{
lean_del_object(v___x_483_);
lean_dec(v_head_480_);
v_a_477_ = v_tail_481_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0___boxed(lean_object* v_rid_492_, lean_object* v_a_493_, lean_object* v_a_494_){
_start:
{
lean_object* v_res_495_; 
v_res_495_ = lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0(v_rid_492_, v_a_493_, v_a_494_);
lean_dec(v_rid_492_);
return v_res_495_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_free(lean_object* v_b_496_, lean_object* v_rid_497_){
_start:
{
lean_object* v_reg_498_; lean_object* v___x_500_; uint8_t v_isShared_501_; uint8_t v_isSharedCheck_517_; 
v_reg_498_ = lean_ctor_get(v_b_496_, 0);
v_isSharedCheck_517_ = !lean_is_exclusive(v_b_496_);
if (v_isSharedCheck_517_ == 0)
{
v___x_500_ = v_b_496_;
v_isShared_501_ = v_isSharedCheck_517_;
goto v_resetjp_499_;
}
else
{
lean_inc(v_reg_498_);
lean_dec(v_b_496_);
v___x_500_ = lean_box(0);
v_isShared_501_ = v_isSharedCheck_517_;
goto v_resetjp_499_;
}
v_resetjp_499_:
{
lean_object* v_bodies_502_; lean_object* v_nextRid_503_; lean_object* v___x_505_; uint8_t v_isShared_506_; uint8_t v_isSharedCheck_516_; 
v_bodies_502_ = lean_ctor_get(v_reg_498_, 0);
v_nextRid_503_ = lean_ctor_get(v_reg_498_, 1);
v_isSharedCheck_516_ = !lean_is_exclusive(v_reg_498_);
if (v_isSharedCheck_516_ == 0)
{
v___x_505_ = v_reg_498_;
v_isShared_506_ = v_isSharedCheck_516_;
goto v_resetjp_504_;
}
else
{
lean_inc(v_nextRid_503_);
lean_inc(v_bodies_502_);
lean_dec(v_reg_498_);
v___x_505_ = lean_box(0);
v_isShared_506_ = v_isSharedCheck_516_;
goto v_resetjp_504_;
}
v_resetjp_504_:
{
lean_object* v___x_507_; lean_object* v___x_508_; lean_object* v___x_510_; 
v___x_507_ = lean_box(0);
v___x_508_ = lp_physicsbridge_List_filterTR_loop___at___00PhysicsBridge_Bridge_free_spec__0(v_rid_497_, v_bodies_502_, v___x_507_);
if (v_isShared_506_ == 0)
{
lean_ctor_set(v___x_505_, 0, v___x_508_);
v___x_510_ = v___x_505_;
goto v_reusejp_509_;
}
else
{
lean_object* v_reuseFailAlloc_515_; 
v_reuseFailAlloc_515_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_515_, 0, v___x_508_);
lean_ctor_set(v_reuseFailAlloc_515_, 1, v_nextRid_503_);
v___x_510_ = v_reuseFailAlloc_515_;
goto v_reusejp_509_;
}
v_reusejp_509_:
{
uint8_t v___x_511_; lean_object* v___x_513_; 
v___x_511_ = 2;
if (v_isShared_501_ == 0)
{
lean_ctor_set(v___x_500_, 0, v___x_510_);
v___x_513_ = v___x_500_;
goto v_reusejp_512_;
}
else
{
lean_object* v_reuseFailAlloc_514_; 
v_reuseFailAlloc_514_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v_reuseFailAlloc_514_, 0, v___x_510_);
v___x_513_ = v_reuseFailAlloc_514_;
goto v_reusejp_512_;
}
v_reusejp_512_:
{
lean_ctor_set_uint8(v___x_513_, sizeof(void*)*1, v___x_511_);
return v___x_513_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_free___boxed(lean_object* v_b_518_, lean_object* v_rid_519_){
_start:
{
lean_object* v_res_520_; 
v_res_520_ = lp_physicsbridge_PhysicsBridge_Bridge_free(v_b_518_, v_rid_519_);
lean_dec(v_rid_519_);
return v_res_520_;
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_compile(lean_object* v_b_521_){
_start:
{
lean_object* v_reg_522_; lean_object* v___x_524_; uint8_t v_isShared_525_; uint8_t v_isSharedCheck_530_; 
v_reg_522_ = lean_ctor_get(v_b_521_, 0);
v_isSharedCheck_530_ = !lean_is_exclusive(v_b_521_);
if (v_isSharedCheck_530_ == 0)
{
v___x_524_ = v_b_521_;
v_isShared_525_ = v_isSharedCheck_530_;
goto v_resetjp_523_;
}
else
{
lean_inc(v_reg_522_);
lean_dec(v_b_521_);
v___x_524_ = lean_box(0);
v_isShared_525_ = v_isSharedCheck_530_;
goto v_resetjp_523_;
}
v_resetjp_523_:
{
uint8_t v___x_526_; lean_object* v___x_528_; 
v___x_526_ = 1;
if (v_isShared_525_ == 0)
{
v___x_528_ = v___x_524_;
goto v_reusejp_527_;
}
else
{
lean_object* v_reuseFailAlloc_529_; 
v_reuseFailAlloc_529_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v_reuseFailAlloc_529_, 0, v_reg_522_);
v___x_528_ = v_reuseFailAlloc_529_;
goto v_reusejp_527_;
}
v_reusejp_527_:
{
lean_ctor_set_uint8(v___x_528_, sizeof(void*)*1, v___x_526_);
return v___x_528_;
}
}
}
}
LEAN_EXPORT lean_object* lp_physicsbridge_PhysicsBridge_Bridge_step(lean_object* v_b_531_){
_start:
{
uint8_t v_phase_532_; 
v_phase_532_ = lean_ctor_get_uint8(v_b_531_, sizeof(void*)*1);
if (v_phase_532_ == 1)
{
lean_object* v___x_533_; 
v___x_533_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_533_, 0, v_b_531_);
return v___x_533_;
}
else
{
lean_object* v___x_534_; 
lean_dec_ref(v_b_531_);
v___x_534_ = lean_box(0);
return v___x_534_;
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_physicsbridge_PhysicsBridge(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
