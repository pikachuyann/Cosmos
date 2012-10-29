//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford, formerly University of Birmingham)
//	
//------------------------------------------------------------------------------
//	
//	This file is part of PRISM.
//	
//	PRISM is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//	
//	PRISM is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//	
//	You should have received a copy of the GNU General Public License
//	along with PRISM; if not, write to the Free Software Foundation,
//	Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//	
//==============================================================================

package parser.ast;

import java.util.Vector;

import parser.visitor.*;
import prism.PrismLangException;

// class to store list of formulas

public class FormulaList extends ASTElement
{
	// Name/expression pairs to define formulas
	private Vector<String> names;
	private Vector<Expression> formulas;
	// We also store an ExpressionIdent to match each name.
	// This is to just to provide positional info.
	private Vector<ExpressionIdent> nameIdents;

	// Constructor

	public FormulaList()
	{
		names = new Vector<String>();
		formulas = new Vector<Expression>();
		nameIdents = new Vector<ExpressionIdent>();
	}

	// Set methods

	public void addFormula(ExpressionIdent n, Expression f)
	{
		names.addElement(n.getName());
		formulas.addElement(f);
		nameIdents.addElement(n);
	}

	public void setFormulaName(int i, ExpressionIdent n)
	{
		names.set(i, n.getName());
		nameIdents.set(i, n);
	}

	public void setFormula(int i, Expression f)
	{
		formulas.set(i, f);
	}

	// Get methods

	public int size()
	{
		return formulas.size();
	}

	public String getFormulaName(int i)
	{
		return names.elementAt(i);
	}

	public Expression getFormula(int i)
	{
		return formulas.elementAt(i);
	}

	public ExpressionIdent getFormulaNameIdent(int i)
	{
		return nameIdents.elementAt(i);
	}

	/**
	 * Get the index of a formula by its name (returns -1 if it does not exist).
	 */
	public int getFormulaIndex(String s)
	{
		return names.indexOf(s);
	}

	/**
	 * Find cyclic dependencies.
	 */
	public void findCycles() throws PrismLangException
	{
		int i, j, k, l, n, firstCycle = -1;
		Vector<String> v;
		boolean matrix[][];
		boolean foundCycle = false;

		// initialise boolean matrix
		n = size();
		matrix = new boolean[n][n];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				matrix[i][j] = false;
			}
		}

		// determine which formulas contain which other formulas
		// and store this info in boolean matrix
		for (i = 0; i < n; i++) {
			v = getFormula(i).getAllFormulas();
			for (j = 0; j < v.size(); j++) {
				k = getFormulaIndex((String) v.elementAt(j));
				if (k != -1) {
					matrix[i][k] = true;
				}
			}
		}

		// check for dependencies
		// (loop a maximum of n times)
		// (n = max length of possible cycle)
		for (i = 0; i < n; i++) {
			// see if there is a cycle yet
			for (j = 0; j < n; j++) {
				if (matrix[j][j]) {
					foundCycle = true;
					firstCycle = j;
					break;
				}
			}
			// if so, stop
			if (foundCycle)
				break;
			// extend dependencies
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					if (matrix[j][k]) {
						for (l = 0; l < n; l++) {
							matrix[j][l] |= matrix[k][l];
						}
					}
				}
			}
		}

		// report dependency
		if (foundCycle) {
			String s = "Cyclic dependency in definition of formula \"" + getFormulaName(firstCycle) + "\"";
			throw new PrismLangException(s, getFormula(firstCycle));
		}
	}

	// Methods required for ASTElement:

	/**
	 * Visitor method.
	 */
	public Object accept(ASTVisitor v) throws PrismLangException
	{
		return v.visit(this);
	}

	/**
	 * Convert to string.
	 */
	public String toString()
	{
		String s = "";
		int i, n;

		n = size();
		for (i = 0; i < n; i++) {
			s += "formula " + getFormulaName(i);
			s += " = " + getFormula(i) + ";\n";
		}

		return s;
	}

	/**
	 * Perform a deep copy.
	 */
	public ASTElement deepCopy()
	{
		int i, n;
		FormulaList ret = new FormulaList();
		n = size();
		for (i = 0; i < n; i++) {
			ret.addFormula((ExpressionIdent)getFormulaNameIdent(i).deepCopy(), getFormula(i).deepCopy());
		}
		ret.setPosition(this);
		return ret;
	}
}

// ------------------------------------------------------------------------------
