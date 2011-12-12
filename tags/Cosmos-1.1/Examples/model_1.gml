<?xml version="1.0" encoding="UTF-8"?>

<model formalismUrl="http://alligator.lip6.fr/pt-net.fml"
    xmlns="http://gml.lip6.fr/model">
	<attribute name="authors"></attribute>
	<attribute name="title"></attribute>
	<attribute name="date"></attribute>
	<attribute name="note">Designed with Coloane</attribute>
	<attribute name="version">0,0</attribute>

	<node id="3" nodeType="place">
		<attribute name="name">p1</attribute>
		<attribute name="marking">1</attribute>
	</node>
	<node id="4" nodeType="place">
		<attribute name="name">P2</attribute>
		<attribute name="marking">2</attribute>
	</node>
	<node id="5" nodeType="transition">
		<attribute name="name">t1</attribute>
	</node>
	<node id="6" nodeType="transition">
		<attribute name="name">t2</attribute>
	</node>

	<arc id="7" arcType="arc" source="3" target="5">
		<attribute name="valuation">1</attribute>
	</arc>
	<arc id="8" arcType="arc" source="5" target="4">
		<attribute name="valuation">1</attribute>
	</arc>
	<arc id="9" arcType="arc" source="4" target="6">
		<attribute name="valuation">1</attribute>
	</arc>
	<arc id="10" arcType="arc" source="6" target="3">
		<attribute name="valuation">1</attribute>
	</arc>

</model>