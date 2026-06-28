/*
 * QuickJS opcode definitions
 * 
 * Copyright (c) 2017-2018 Fabrice Bellard
 * Copyright (c) 2017-2018 Charlie Gordon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifdef FMT
FMT(none)
FMT(none_int)
FMT(none_loc)
FMT(none_arg)
FMT(none_var_ref)
FMT(u8)
FMT(i8)
FMT(loc8)
FMT(const8)
FMT(label8)
FMT(u16)
FMT(i16)
FMT(label16)
FMT(npop)
FMT(npopx)
FMT(npop_u16)
FMT(loc)
FMT(arg)
FMT(var_ref)
FMT(u32)
FMT(i32)
FMT(const)
FMT(label)
FMT(atom)
FMT(atom_u8)
FMT(atom_u16)
FMT(atom_label_u8)
FMT(atom_label_u16)
FMT(label_u16)
#undef FMT
#endif /* FMT */

#ifdef DEF

#ifndef def
#define def(id, size, n_pop, n_push, f) DEF(id, size, n_pop, n_push, f)
#endif

DEF(          rot4l, 1, 4, 4, none) /* x a b c -> a b c x */

/* push values */
DEF(with_delete_var, 10, 1, 0, atom_label_u8)     /* must be in the same order as scope_xxx */
DEF(       get_arg1, 1, 0, 1, none_arg)
DEF(          rot3l, 1, 3, 3, none) /* x a b -> a b x */
DEF(          perm4, 1, 4, 4, none) /* obj prop a b -> a obj prop b */
DEF(        inc_loc, 2, 0, 0, loc8)
DEF(         delete, 1, 2, 1, none)
DEF(            lte, 1, 2, 1, none)
DEF(     yield_star, 1, 1, 2, none)
DEF(            dup, 1, 1, 2, none) /* a -> a a */
DEF(  iterator_next, 1, 4, 4, none)
DEF(     instanceof, 1, 2, 1, none)
DEF(  iterator_call, 2, 4, 5, u8)

DEF(typeof_is_undefined, 1, 1, 1, none)
def(get_field_opt_chain, 5, 1, 1, atom) /* emitted in phase 1, removed in phase 2 */
DEF(    set_var_ref, 3, 1, 1, var_ref) /* must come after put_var_ref */
DEF(             in, 1, 2, 1, none)
DEF(      fclosure8, 2, 0, 1, const8) /* must follow push_const8 */
DEF(         goto16, 3, 0, 0, label16)
DEF(         push_6, 1, 0, 1, none_int)
DEF(     push_false, 1, 0, 1, none)
DEF(          yield, 1, 1, 2, none)
DEF(          call0, 1, 1, 1, npopx)
DEF( special_object, 2, 0, 1, u8) /* only used at the start of a function */
DEF(         push_7, 1, 0, 1, none_int)
DEF(       if_false, 5, 1, 0, label)
DEF(   with_get_ref, 10, 1, 0, atom_label_u8)     /* must be in the same order as scope_xxx */
DEF(             gt, 1, 2, 1, none)
DEF(     delete_var, 5, 0, 1, atom)
DEF(        push_i8, 2, 0, 1, i8)
DEF(    put_var_ref, 3, 1, 0, var_ref) /* must come after get_var_ref */

DEF(          perm3, 1, 3, 3, none) /* obj a b -> a obj b */
DEF( put_var_strict, 5, 2, 0, atom) /* for strict mode variable write */
DEF(   define_field, 5, 2, 1, atom)
DEF(       put_loc1, 1, 1, 0, none_loc)
DEF(            dec, 1, 1, 1, none)
DEF(        put_var, 5, 1, 0, atom) /* must come after get_var */
DEF(      nip_catch, 1, 2, 1, none) /* catch ... a -> a */
DEF(       set_arg2, 1, 1, 1, none_arg)
DEF(   make_arg_ref, 7, 0, 2, atom_u16)
DEF(   get_var_ref0, 1, 0, 1, none_var_ref)
DEF(       get_loc8, 2, 0, 1, loc8)
def(  scope_put_var, 7, 1, 0, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF(push_atom_value, 5, 0, 1, atom)
DEF(           lnot, 1, 1, 1, none)
def(       line_num, 5, 0, 0, u32) /* emitted in phase 1, removed in phase 3 */
DEF(          await, 1, 1, 1, none)
DEF(     to_propkey, 1, 1, 1, none)
DEF(copy_data_properties, 2, 3, 3, u8)
                                       bytecode string */
DEF(         push_1, 1, 0, 1, none_int)

DEF(            ret, 1, 1, 0, none) /* used to return from the finally block */
DEF(       post_dec, 1, 1, 2, none)
DEF(           eval, 5, 1, 1, npop_u16) /* func args... -> ret_val */
DEF(         regexp, 1, 2, 1, none) /* create a RegExp object from the pattern and a
DEF(push_empty_string, 1, 0, 1, none)

DEF(  put_loc_check_init, 3, 1, 0, loc)

DEF(            pow, 1, 2, 1, none)
DEF(          gosub, 5, 0, 0, label) /* used to execute the finally block */
DEF(      if_false8, 2, 1, 0, label8)
DEF(            add, 1, 2, 1, none)
DEF(            mul, 1, 2, 1, none)
DEF(        insert2, 1, 2, 3, none) /* obj a -> a obj a (dup_x1) */
DEF(        is_null, 1, 1, 1, none)
DEF(           null, 1, 0, 1, none)
DEF(            div, 1, 2, 1, none)
DEF(      to_object, 1, 1, 1, none)
DEF(          call2, 1, 1, 1, npopx)
DEF(    to_propkey2, 1, 2, 2, none)
def(scope_get_private_field, 7, 1, 1, atom_u16) /* obj -> value, emitted in phase 1, removed in phase 2 */
DEF(    push_const8, 2, 0, 1, const8)
DEF(  with_make_ref, 10, 1, 0, atom_label_u8)     /* must be in the same order as scope_xxx */
DEF(       set_loc1, 1, 1, 1, none_loc)
DEF(   set_var_ref2, 1, 1, 1, none_var_ref)
DEF(      strict_eq, 1, 2, 1, none)
DEF(    get_var_ref, 3, 0, 1, var_ref) 
DEF(       put_arg0, 1, 1, 0, none_arg)
DEF(         push_5, 1, 0, 1, none_int)
DEF(     private_in, 1, 2, 1, none)
DEF(put_super_value, 1, 4, 0, none) /* this obj prop value -> */
DEF(          apply, 3, 3, 1, u16)
DEF(       get_loc3, 1, 0, 1, none_loc)

DEF(       set_arg1, 1, 1, 1, none_arg)
def(scope_get_var_checkthis, 7, 0, 1, atom_u16) /* emitted in phase 1, removed in phase 2, only used to return 'this' in derived class constructors */
DEF(       push_i32, 5, 0, 1, i32)
def( set_class_name, 5, 1, 1, u32) /* emitted in phase 1, removed in phase 2 */
DEF(      tail_call, 3, 1, 0, npop) /* arguments are not counted in n_pop */
DEF(           dup2, 1, 2, 4, none) /* a b -> a b a b */
def(    leave_scope, 3, 0, 0, u16)  /* emitted in phase 1, removed in phase 2 */
DEF(   with_get_var, 10, 1, 0, atom_label_u8)     /* must be in the same order as scope_xxx */
DEF(           call, 3, 1, 1, npop) /* arguments are not counted in n_pop */
DEF(   for_of_start, 1, 1, 3, none)
def(scope_put_private_field, 7, 2, 0, atom_u16) /* obj value ->, emitted in phase 1, removed in phase 2 */
DEF(   set_var_ref0, 1, 1, 1, none_var_ref)
DEF(   put_var_ref3, 1, 1, 0, none_var_ref)
DEF(         push_4, 1, 0, 1, none_int)
DEF(set_loc_uninitialized, 3, 0, 0, loc)
DEF(       fclosure, 5, 0, 1, const) /* must follow push_const */
DEF(      undefined, 1, 0, 1, none)
DEF(       push_i16, 3, 0, 1, i16)
DEF( private_symbol, 5, 0, 1, atom)
DEF(iterator_check_object, 1, 1, 1, none)
DEF(   make_loc_ref, 7, 0, 2, atom_u16)
DEF(     get_length, 1, 1, 1, none)
DEF(    throw_error, 6, 0, 0, atom_u8)
DEF(define_private_field, 1, 3, 1, none) /* obj prop value -> obj */

//DEF(      to_string, 1, 1, 1, none)
DEF(   return_async, 1, 1, 0, none)

DEF(   get_var_ref2, 1, 0, 1, none_var_ref)
DEF(check_define_var, 6, 0, 0, atom_u8)
DEF(    define_func, 6, 1, 0, atom_u8)
DEF(          rot5l, 1, 5, 5, none) /* x a b c d -> a b c d x */
DEF(           rest, 3, 0, 1, u16) /* only used at the start of a function */

DEF(      push_this, 1, 0, 1, none) /* only used at the start of a function */
DEF(        set_loc, 3, 1, 1, loc) /* must come after put_loc */
DEF(iterator_get_value_done, 1, 1, 2, none)

DEF(call_constructor, 3, 2, 1, npop) /* func new.target args -> ret. arguments are not counted in n_pop */
DEF(is_undefined_or_null, 1, 1, 1, none)
DEF(       set_loc2, 1, 1, 1, none_loc)
DEF(   for_in_start, 1, 1, 1, none)
def(    enter_scope, 3, 0, 0, u16)  /* emitted in phase 1, removed in phase 2 */
DEF(           drop, 1, 1, 0, none) /* a -> */
DEF(     apply_eval, 3, 2, 1, u16) /* func array -> ret_eval */
DEF(define_method_computed, 2, 3, 1, u8) /* must come after define_method */
DEF(      set_proto, 1, 2, 1, none)
DEF(        insert3, 1, 3, 4, none) /* obj prop a -> a obj prop a (dup_x2) */
DEF(get_super_value, 1, 3, 1, none) /* this obj prop -> value */
DEF(  get_array_el2, 1, 2, 2, none) /* obj prop -> obj value */
DEF(   set_var_ref1, 1, 1, 1, none_var_ref)
DEF(            sar, 1, 2, 1, none)

/* arithmetic/logic operations */
DEF(set_name_computed, 1, 2, 2, none)
DEF(get_var_ref_check, 3, 0, 1, var_ref) 
DEF(define_array_el, 1, 3, 2, none)
DEF(with_get_ref_undef, 10, 1, 0, atom_label_u8)
DEF(   get_var_ref3, 1, 0, 1, none_var_ref)
DEF(      add_brand, 1, 2, 0, none) /* this_obj home_obj -> */
DEF(put_var_ref_check_init, 3, 1, 0, var_ref)
DEF(async_yield_star, 1, 1, 2, none)
DEF(   put_var_ref2, 1, 1, 0, none_var_ref)
DEF(          call3, 1, 1, 1, npopx)
DEF(            shr, 1, 2, 1, none)
DEF(   get_array_el, 1, 2, 1, none)
DEF(          swap2, 1, 4, 4, none) /* a b c d -> c d a b */

DEF(       set_arg3, 1, 1, 1, none_arg)
DEF(  get_ref_value, 1, 2, 3, none)
DEF(   put_var_ref0, 1, 1, 0, none_var_ref)
DEF(     array_from, 3, 0, 1, npop) /* arguments are not counted in n_pop */
DEF(put_var_ref_check, 3, 1, 0, var_ref) /* must come after get_var_ref_check */
DEF(            sub, 1, 2, 1, none)
DEF(          rot3r, 1, 3, 3, none) /* a b x -> x a b */
DEF( put_private_field, 1, 3, 0, none) /* obj value prop -> */
DEF(       set_name, 5, 1, 1, atom)
DEF(       put_loc0, 1, 1, 0, none_loc)
def(get_array_el_opt_chain, 1, 2, 1, none) /* emitted in phase 1, removed in phase 2 */
DEF(        insert4, 1, 4, 5, none) /* this obj prop a -> a this obj prop a */
DEF(        get_var, 5, 0, 1, atom) /* throw an exception if the variable does not exist */
DEF(         import, 1, 1, 1, none) /* dynamic module import */
DEF(       get_arg0, 1, 0, 1, none_arg)
DEF(         append, 1, 3, 2, none) /* append enumerated object, update length */
DEF(          throw, 1, 1, 0, none)
DEF(      mul_pow10, 1, 2, 1, none)
DEF(       get_loc2, 1, 0, 1, none_loc)
DEF(check_ctor_return, 1, 1, 2, none)
DEF(        dec_loc, 2, 0, 0, loc8)
DEF(      put_field, 5, 2, 0, atom)
DEF(   return_undef, 1, 0, 0, none)
#ifdef CONFIG_BIGNUM
DEF(        if_true, 5, 1, 0, label) /* must come after if_false */
#endif
/* must be the last non short and non temporary opcode */

/* temporary opcodes: never emitted in the final bytecode */

DEF(    push_minus1, 1, 0, 1, none_int)


/* the following opcodes must be in the same order as the 'with_x' and
   get_var_undef, get_var and put_var opcodes */
DEF(    for_of_next, 2, 3, 5, u8)
DEF(   define_class, 6, 2, 2, atom_u8) /* parent ctor -> ctor proto */
DEF(set_home_object, 1, 2, 2, none)
DEF(          goto8, 2, 0, 0, label8) /* must come after if_true8 */
DEF(       if_true8, 2, 1, 0, label8) /* must come after if_false8 */
DEF(         push_3, 1, 0, 1, none_int)
DEF(            xor, 1, 2, 1, none)
DEF(            nop, 1, 0, 0, none) 
DEF(        get_arg, 3, 0, 1, arg)
DEF(          call1, 1, 1, 1, npopx)
DEF(    call_method, 3, 2, 1, npop) /* arguments are not counted in n_pop */
DEF(           dup3, 1, 3, 6, none) /* a b c -> a b c a b c */
DEF(          catch, 5, 0, 1, label)
DEF(         object, 1, 0, 1, none)
    

#if SHORT_OPCODES
DEF(         typeof, 1, 1, 1, none)
DEF(   put_var_ref1, 1, 1, 0, none_var_ref)
DEF(            mod, 1, 2, 1, none)
DEF(      close_loc, 3, 0, 0, loc)
DEF(get_loc_checkthis, 3, 0, 1, loc)
DEF(for_await_of_start, 1, 1, 3, none)
DEF(        set_arg, 3, 1, 1, arg) /* must come after put_arg */
DEF(         push_2, 1, 0, 1, none_int)
DEF(            gte, 1, 2, 1, none)
DEF(       put_arg3, 1, 1, 0, none_arg)
DEF(  get_loc_check, 3, 0, 1, loc)
DEF(       put_loc8, 2, 1, 0, loc8)
DEF(        put_loc, 3, 1, 0, loc) /* must come after get_loc */

DEF(   make_var_ref, 5, 0, 2, atom)
DEF(            shl, 1, 2, 1, none)

DEF(            neq, 1, 2, 1, none)
def(scope_delete_var, 7, 0, 1, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF( typeof_is_function, 1, 1, 1, none)
DEF(            and, 1, 2, 1, none)
DEF(  get_var_undef, 5, 0, 1, atom) /* push undefined if the variable does not exist */
DEF(       get_arg3, 1, 0, 1, none_arg)
DEF(     push_const, 5, 0, 1, const)
DEF(   get_var_ref1, 1, 0, 1, none_var_ref)
DEF(      get_field, 5, 1, 1, atom)
DEF(  define_method, 6, 2, 1, atom_u8)
DEF(        put_arg, 3, 1, 0, arg) /* must come after get_arg */
def( scope_make_ref, 11, 0, 2, atom_label_u16) /* emitted in phase 1, removed in phase 2 */
DEF(        add_loc, 2, 1, 0, loc8)
DEF(      check_var, 5, 0, 1, atom) /* check if a variable exists */
DEF(            inc, 1, 1, 1, none)
DEF(       post_inc, 1, 1, 2, none)
DEF(       set_loc3, 1, 1, 1, none_loc)
def(          label, 5, 0, 0, label) /* emitted in phase 1, removed in phase 3 */
DEF(     check_ctor, 1, 0, 0, none)
DEF(            not, 1, 1, 1, none)
DEF(        get_loc, 3, 0, 1, loc)
def(scope_get_var_undef, 7, 0, 1, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF(tail_call_method, 3, 2, 0, npop) /* arguments are not counted in n_pop */
DEF(       put_arg1, 1, 1, 0, none_arg)
DEF(           plus, 1, 1, 1, none)
DEF(             lt, 1, 2, 1, none)
DEF(  initial_yield, 1, 0, 0, none)
def(scope_get_private_field2, 7, 1, 2, atom_u16) /* obj -> obj value, emitted in phase 1, removed in phase 2 */
def(  scope_get_var, 7, 0, 1, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF(           goto, 5, 0, 0, label) /* must come after if_true */
DEF(       get_loc0, 1, 0, 1, none_loc)
DEF(             eq, 1, 2, 1, none)
DEF(       set_arg0, 1, 1, 1, none_arg)
DEF(       set_loc8, 2, 1, 1, loc8)
DEF(       get_loc1, 1, 0, 1, none_loc)


DEF( iterator_close, 1, 3, 0, none)
DEF(    for_in_next, 1, 1, 3, none)
DEF(      push_true, 1, 0, 1, none)

DEF(  put_ref_value, 1, 3, 0, none)
def(scope_put_var_init, 7, 0, 2, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF(   put_var_init, 5, 1, 0, atom) /* must come after put_var. Used to initialize a global lexical variable */

DEF(         return, 1, 1, 0, none)
DEF(   with_put_var, 10, 2, 1, atom_label_u8)     /* must be in the same order as scope_xxx */
DEF(   set_var_ref3, 1, 1, 1, none_var_ref)
DEF(             or, 1, 2, 1, none)
DEF(   define_class_computed, 6, 3, 3, atom_u8) /* field_name parent ctor -> field_name ctor proto (class with computed name) */
DEF(       put_loc3, 1, 1, 0, none_loc)
DEF(         push_0, 1, 0, 1, none_int)
def(scope_in_private_field, 7, 1, 1, atom_u16) /* obj -> res emitted in phase 1, removed in phase 2 */
DEF(     strict_neq, 1, 2, 1, none)
DEF( get_private_field, 1, 2, 1, none) /* obj prop -> value */
DEF(           swap, 1, 2, 2, none) /* a b -> b a */
DEF(            nip, 1, 2, 1, none) /* a b -> b */
DEF(       put_loc2, 1, 1, 0, none_loc)
DEF(       put_arg2, 1, 1, 0, none_arg)
DEF(       math_mod, 1, 2, 1, none)
DEF(       set_loc0, 1, 1, 1, none_loc)
DEF(            neg, 1, 1, 1, none)
DEF(    check_brand, 1, 2, 2, none) /* this_obj func -> this_obj func */
DEF(make_var_ref_ref, 7, 0, 2, atom_u16)
DEF(   is_undefined, 1, 1, 1, none)
DEF(     define_var, 6, 0, 0, atom_u8)
DEF(     get_field2, 5, 1, 2, atom)
def(  scope_get_ref, 7, 0, 2, atom_u16) /* emitted in phase 1, removed in phase 2 */
DEF(          perm5, 1, 5, 5, none) /* this obj prop a b -> a this obj prop b */
DEF(           dup1, 1, 2, 3, none) /* a b -> a a b */
DEF(   put_array_el, 1, 3, 0, none)
DEF(       get_arg2, 1, 0, 1, none_arg)
DEF(  put_loc_check, 3, 1, 0, loc) /* must come after get_loc_check */
DEF(      get_super, 1, 1, 1, none)
DEF(invalid, 1, 0, 0, none) /* never emitted */
DEF(           nip1, 1, 3, 2, none) /* a b c -> b c */
#endif

#undef DEF
#undef def

#define OP_XOR_KEY 0xC5
#endif  /* DEF */