/**
 * SuperFX assembly decoder
 */

/**
 * case 0: no argument optcodes
 * eg. ALT1, GETBH etc...
 */
case 0:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
      if (opt_tmp->alt != ALT0)
      {
	output_assembled_opcode(opt_tmp, "d%d ", opt_tmp->alt);
      }
      output_assembled_opcode(opt_tmp, "d%d ", opt_tmp->hex);
      i = inz;
      return SUCCEEDED;
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 1: a register specify optcodes
 * eg. ADC R0, MULT R0
 */
case 1:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == '*') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;

      if (z != SUCCEEDED || !(0 <= d && d < 16) )
	break;

      /* undefined optcodes check */
      if ( (opt_tmp->hex == 0x30 || opt_tmp->hex == 0x40) && d > 11)
	break;
      if ( d == 0 && (opt_tmp->hex == 0x70 || opt_tmp->hex == 0xC0) )
	break;
      if ( d == 15 && (opt_tmp->hex == 0xD0 || opt_tmp->hex == 0xE0) )
	break;
      if ( (d < 8 || d > 13) && opt_tmp->hex == 0x90 ){
	  break;
      }

      d |= opt_tmp->hex;

      for (x++ ; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	  if (opt_tmp->alt != ALT0)
	  {
	    output_assembled_opcode(opt_tmp, "d%d ", opt_tmp->alt);
	  }
	  output_assembled_opcode(opt_tmp, "d%d ", d);
	  i = inz;
	  return SUCCEEDED;
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 2: a 4-bits value specify optcodes
 * eg. ADC #0, LINK #1
 */
case 2:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == '*') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;

      if (z != SUCCEEDED || !(0 <= d && d < 16) )
	break;

      /* undefined optcodes check */
      if ( (opt_tmp->hex == 0x30 || opt_tmp->hex == 0x40) && d > 11)
	break;
      if( !d && (opt_tmp->hex == 0x70 || opt_tmp->hex == 0xC0) )
	break;
      if( d == 15 && (opt_tmp->hex == 0xD0 || opt_tmp->hex == 0xE0) )
	break;
      if ( (d < 1 || d > 4) && opt_tmp->hex == 0x90 )
	break;

      d |= opt_tmp->hex;

      for (x++ ; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	  if (opt_tmp->alt != ALT0)
	  {
	    output_assembled_opcode(opt_tmp, "d%d ", opt_tmp->alt);
	  }
	  output_assembled_opcode(opt_tmp, "d%d ", d);
	  i = inz;
	  return SUCCEEDED;
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 3: Branch code
 * eg. BCC x, BGE x
 */
case 3:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == 'x') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;
      if (!(z == SUCCEEDED || z == INPUT_NUMBER_ADDRESS_LABEL || z == INPUT_NUMBER_STACK))
	return FAILED;
      if (z == SUCCEEDED && (d > 255 || d < -128))
	break;

      for (x++; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	  if (z == SUCCEEDED)
	    output_assembled_opcode(opt_tmp, "d%d d%d ", opt_tmp->hex, d);
	  else if (z == INPUT_NUMBER_ADDRESS_LABEL)
	    output_assembled_opcode(opt_tmp, "k%d d%d R%s ", active_file_info_last->line_current, opt_tmp->hex, label);
	  else {
	    output_assembled_opcode(opt_tmp, "d%d c%d ", opt_tmp->hex, latest_stack);
	  }

	  i = inz;
	  return SUCCEEDED;
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 4: regisrer and 8bits value
 *    only IBT R*, #x
 */
case 4:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == '*') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;
      if (!(z == SUCCEEDED))
	return FAILED;
      if (z == SUCCEEDED && !(0 <= d && d < 16))
	break;
      d |= opt_tmp->hex;

      e = d;
      v = z;
      for (x++; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == 'x') {
	  y = i;
	  i = inz;
	  z = input_number();
	  inz = i;
	  i = y;
	  if (!(z == SUCCEEDED || z == INPUT_NUMBER_ADDRESS_LABEL || z == INPUT_NUMBER_STACK))
	    return FAILED;
	  if (z != SUCCEEDED && (d > 255 || d < -128) )
	    break;

	  for (x++; x < OP_SIZE_MAX; inz++, x++) {
	    if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	      if (v == SUCCEEDED)
		output_assembled_opcode(opt_tmp, "d%d ", e);

	      if (z == SUCCEEDED)
		output_assembled_opcode(opt_tmp, "d%d ", d);
	      else if (z == INPUT_NUMBER_ADDRESS_LABEL)
		output_assembled_opcode(opt_tmp, "k%d R%s ", active_file_info_last->line_current, label);
	      else
		output_assembled_opcode(opt_tmp, "c%d ", latest_stack);

	      i = inz;
	      return SUCCEEDED;
	    }
	    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	      break;
	  }
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 5: regisrer and 16bits #value
 *    IWT only
 * case 6: register and 16bits rabel addr value
 */
case 5:
case 6:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == '*') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;
      if (z == SUCCEEDED && !(0 <= d && d < 16))
	break;
      d |= opt_tmp->hex;

      e = d;
      v = z;
      for (x++; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == '?') {
	  y = i;
	  i = inz;
	  z = input_number();
	  inz = i;
	  i = y;
	  if (z != SUCCEEDED && (d > 65535 || d < -32768) )
	    break;

	  for (x++; x < OP_SIZE_MAX; inz++, x++) {
	    if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	      if (opt_tmp->alt != ALT0)
	      {
		output_assembled_opcode(opt_tmp, "d%d ", opt_tmp->alt);
	      }
	      if (v == SUCCEEDED)
		output_assembled_opcode(opt_tmp, "d%d ", e);

	      if (z == SUCCEEDED)
		output_assembled_opcode(opt_tmp, "y%d ", d);
	      else if (z == INPUT_NUMBER_ADDRESS_LABEL)
		output_assembled_opcode(opt_tmp, "k%d r%s ", active_file_info_last->line_current, label);
	      else
		output_assembled_opcode(opt_tmp, "C%d ", latest_stack);

	      i = inz;
	      return SUCCEEDED;
	    }
	    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	      break;
	  }
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

/**
 * case 9: Register transfer optcodes
 *  MOVE R*,R*  and MOVES R*,R*
 */
case 9:
  for ( ; x < OP_SIZE_MAX; inz++, x++) {
    if (opt_tmp->op[x] == '*') {
      y = i;
      i = inz;
      z = input_number();
      inz = i;
      i = y;
      if (z == SUCCEEDED && !(0 <= d && d < 16))
	break;

      d |= opt_tmp->hex;

      e = d;
      v = z;
      for (x++; x < OP_SIZE_MAX; inz++, x++) {
	if (opt_tmp->op[x] == '*') {
	  y = i;
	  i = inz;
	  z = input_number();
	  inz = i;
	  i = y;
	  if (z != SUCCEEDED && !(0 <= d && d < 16) )
	    break;

	  e |= (d << 8);

	  for (x++; x < OP_SIZE_MAX; inz++, x++) {
	    if (opt_tmp->op[x] == 0 && buffer[inz] == 0x0A) {
	      if (v == SUCCEEDED && z == SUCCEEDED)
		output_assembled_opcode(opt_tmp, "y%d", e);

	      i = inz;
	      return SUCCEEDED;
	    }
	    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	      break;
	  }
	}
	if (opt_tmp->op[x] != toupper((int)buffer[inz]))
	  break;
      }
    }
    if (opt_tmp->op[x] != toupper((int)buffer[inz]))
      break;
  }
  break;

